enum cowconfig_operation {
    OP_NO               = 0,    ///< @brief this cowconfig_rule does nothing / empty
    OP_ANY              = 1,    ///< @brief any packet with given ID triggers
    OP_LT               = 2,    ///< @brief less than
    OP_LTE              = 3,    ///< @brief less than or equal
    OP_GTE              = 4,    ///< @brief greater than or equal
    OP_GT               = 5,    ///< @brief greater than
    OP_EQ               = 6,    ///< @brief equal
    OP_NEQ              = 7,    ///< @brief not equal
    OP_RANGE_GT_LT      = 8,    ///< @brief range without borders/limits (a  <   x  <   y)
    OP_RANGE_GTE_LTE    = 9,    ///< @brief range with borders/limits    (a  <=  x  <=  b)
    OP_RANGE_GTE_LT     = 10,   ///< @brief range with left border       (a  <=  x  <=  b)
    OP_RANGE_GT_LTE     = 11,   ///< @brief range with right border      (a  <   x  <=  y)
    OP_NOT_RANGE_GT_LT   = 12,  ///< @brief complementary to OP_RANGE_GT_LT
    OP_NOT_RANGE_GTE_LTE = 13,  ///< @brief complementary to OP_RANGE_GTE_LTE
    OP_NOT_RANGE_GTE_LT  = 14,  ///< @brief complementary to OP_RANGE_GTE_LT
    OP_NOT_RANGE_GT_LTE  = 15   ///< @brief complementary to OP_RANGE_GT_LTE
}
enum cowconfig_packet_method {
    CCPM_LIST           = 0,    ///< @brief list all rules of node
    CCPM_ADD            = 1,    ///< @brief add new rule
    CCPM_DELETE_ALL     = 2,    ///< @brief delete all rules
    CCPM_DELETE_ONE     = 3,    ///< @brief delete rule with specific id
    CCPM_DELETE_ADDR    = 4,    ///< @brief delete all rules with specific source address
    CCPM_ANSWER_LIST    = 5     ///< @brief answer to CCPM_LIST command
}

class cowconfig_rule {
    address     : number;
    operation   : cowconfig_operation;
    action      : number;
    threshold_a  : number;
    threshold_b  : number;

    constructor(new_address: number = 0,
                new_operation: cowconfig_operation = cowconfig_operation.OP_NO,
                new_action: number = 0,
                new_threshold_a: number = 0, new_threshold_b: number = 0) {

        this.address        = new_address;
        this.operation      = new_operation;
        this.action         = new_action;
        this.threshold_a    = new_threshold_a;
        this.threshold_b    = new_threshold_b;
    }

    static fromString(s: string) : cowconfig_rule {
        var address = 0;
        address += (s.charCodeAt(1) << 8);
        address += s.charCodeAt(0);
        var th_a = 0;
        th_a += (s.charCodeAt(5) << 8);
        th_a += s.charCodeAt(4);
        var th_b = 0;
        th_b += (s.charCodeAt(7) << 8);
        th_b += s.charCodeAt(6);

        var r = new cowconfig_rule(address, s.charCodeAt(2), s.charCodeAt(3),
                    th_a, th_b);
        return r;
    }

    toPayload() : string {
        return String.fromCharCode(this.address & 0xFF) +
            String.fromCharCode((this.address >> 8)& 0xFF) +
            String.fromCharCode(this.operation) +
            String.fromCharCode(this.action) +
            String.fromCharCode(this.threshold_a & 0xFF) +
            String.fromCharCode((this.threshold_a >> 8)& 0xFF) +
            String.fromCharCode(this.threshold_b & 0xFF) +
            String.fromCharCode((this.threshold_b >> 8)& 0xFF);
    }
}

class cowconfig_packet {
    id      : number;
    method  : cowconfig_packet_method;
    rule    : cowconfig_rule;

    constructor(new_id: number = 0,
                new_method: cowconfig_packet_method = cowconfig_packet_method.CCPM_LIST,
                new_rule: cowconfig_rule = null) {
        this.id         = new_id;
        this.method     = new_method;
        this.rule       = new_rule;
    }

    static fromString(s: string) : cowconfig_packet {
        var rule_string = s.substr(2, s.length - 2);
        var rule = cowconfig_rule.fromString(rule_string);
        var r = new cowconfig_packet(
            s.charCodeAt(0), s.charCodeAt(1), rule
            );
        return r;
    }

    toCowpacket(address : number) : cowpacket {
        var payload =
            String.fromCharCode(this.id) +
            String.fromCharCode(this.method) +
            ((this.rule) ? this.rule.toPayload() : "");
        return new cowpacket(cowpacket.COWBUS_VERSION, getNextSeqNo(),
            cowpacket.DEFAULT_TTL, address, cowpacket_type.configure, false, btoa(payload));
    }
}
class cowconfig_rule_pool {
    static pool : cowconfig_rule[][];

    static init() : void {
        cowconfig_rule_pool.pool = [];
    }

    static add(node_address : number, id : number, r : cowconfig_rule) {
        if (!(cowconfig_rule_pool.pool[node_address])) {
            cowconfig_rule_pool.pool[node_address] = [];
        }
        cowconfig_rule_pool.pool[node_address][id] = r;
        console.log(cowconfig_rule_pool.pool);

        updateRuleList(node_address); // GUI
    }

    static get_by_node(node_address : number) : cowconfig_rule[] {
        var rules = [];
        if (cowconfig_rule_pool.pool[node_address]) {
            for (var i = 0; i < cowconfig_rule_pool.pool[node_address].length; ++i) {
                rules[i] = cowconfig_rule_pool.pool[node_address][i];
            }
        }
        return rules;
    }

    static delete_one(node_address : number, id : number) : void {
        if (!(cowconfig_rule_pool.pool[node_address]) || !(cowconfig_rule_pool.pool[node_address][id])) {
            return;
        }
        cowconfig_rule_pool.pool[node_address][id] = undefined;

        var pkt = new cowconfig_packet(id, cowconfig_packet_method.CCPM_DELETE_ONE, null);
        var cpkt = pkt.toCowpacket(node_address);
        sock.send(cpkt.generateJSON());

        updateRuleList(node_address); // GUI
    }

    static delete_all(node_address : number) : void {
        if (!(cowconfig_rule_pool.pool[node_address])) {
            return;
        }
        cowconfig_rule_pool.pool[node_address] = undefined;

        var pkt = new cowconfig_packet(0, cowconfig_packet_method.CCPM_DELETE_ALL, null);
        var cpkt = pkt.toCowpacket(node_address);
        sock.send(cpkt.generateJSON());

        updateRuleList(node_address); // GUI
    }
}


// vim: set et ts=4 sw=4 syntax=javascript:
