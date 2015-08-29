var cowconfig_operation;
(function (cowconfig_operation) {
    cowconfig_operation[cowconfig_operation["OP_NO"] = 0] = "OP_NO";
    cowconfig_operation[cowconfig_operation["OP_ANY"] = 1] = "OP_ANY";
    cowconfig_operation[cowconfig_operation["OP_LT"] = 2] = "OP_LT";
    cowconfig_operation[cowconfig_operation["OP_LTE"] = 3] = "OP_LTE";
    cowconfig_operation[cowconfig_operation["OP_GTE"] = 4] = "OP_GTE";
    cowconfig_operation[cowconfig_operation["OP_GT"] = 5] = "OP_GT";
    cowconfig_operation[cowconfig_operation["OP_EQ"] = 6] = "OP_EQ";
    cowconfig_operation[cowconfig_operation["OP_NEQ"] = 7] = "OP_NEQ";
    cowconfig_operation[cowconfig_operation["OP_RANGE_GT_LT"] = 8] = "OP_RANGE_GT_LT";
    cowconfig_operation[cowconfig_operation["OP_RANGE_GTE_LTE"] = 9] = "OP_RANGE_GTE_LTE";
    cowconfig_operation[cowconfig_operation["OP_RANGE_GTE_LT"] = 10] = "OP_RANGE_GTE_LT";
    cowconfig_operation[cowconfig_operation["OP_RANGE_GT_LTE"] = 11] = "OP_RANGE_GT_LTE";
    cowconfig_operation[cowconfig_operation["OP_NOT_RANGE_GT_LT"] = 12] = "OP_NOT_RANGE_GT_LT";
    cowconfig_operation[cowconfig_operation["OP_NOT_RANGE_GTE_LTE"] = 13] = "OP_NOT_RANGE_GTE_LTE";
    cowconfig_operation[cowconfig_operation["OP_NOT_RANGE_GTE_LT"] = 14] = "OP_NOT_RANGE_GTE_LT";
    cowconfig_operation[cowconfig_operation["OP_NOT_RANGE_GT_LTE"] = 15] = "OP_NOT_RANGE_GT_LTE"; ///< @brief complementary to OP_RANGE_GT_LTE
})(cowconfig_operation || (cowconfig_operation = {}));
var cowconfig_packet_method;
(function (cowconfig_packet_method) {
    cowconfig_packet_method[cowconfig_packet_method["CCPM_LIST"] = 0] = "CCPM_LIST";
    cowconfig_packet_method[cowconfig_packet_method["CCPM_ADD"] = 1] = "CCPM_ADD";
    cowconfig_packet_method[cowconfig_packet_method["CCPM_DELETE_ALL"] = 2] = "CCPM_DELETE_ALL";
    cowconfig_packet_method[cowconfig_packet_method["CCPM_DELETE_ONE"] = 3] = "CCPM_DELETE_ONE";
    cowconfig_packet_method[cowconfig_packet_method["CCPM_DELETE_ADDR"] = 4] = "CCPM_DELETE_ADDR";
    cowconfig_packet_method[cowconfig_packet_method["CCPM_ANSWER_LIST"] = 5] = "CCPM_ANSWER_LIST"; ///< @brief answer to CCPM_LIST command
})(cowconfig_packet_method || (cowconfig_packet_method = {}));
var cowconfig_rule = (function () {
    function cowconfig_rule(new_address, new_operation, new_action, new_threshold_a, new_threshold_b) {
        if (new_address === void 0) { new_address = 0; }
        if (new_operation === void 0) { new_operation = 0 /* OP_NO */; }
        if (new_action === void 0) { new_action = 0; }
        if (new_threshold_a === void 0) { new_threshold_a = 0; }
        if (new_threshold_b === void 0) { new_threshold_b = 0; }
        this.address = new_address;
        this.operation = new_operation;
        this.action = new_action;
        this.threshold_a = new_threshold_a;
        this.threshold_b = new_threshold_b;
    }
    cowconfig_rule.fromString = function (s) {
        var address = 0;
        address += (s.charCodeAt(1) << 8);
        address += s.charCodeAt(0);
        var th_a = 0;
        th_a += (s.charCodeAt(5) << 8);
        th_a += s.charCodeAt(4);
        var th_b = 0;
        th_b += (s.charCodeAt(7) << 8);
        th_b += s.charCodeAt(6);
        var r = new cowconfig_rule(address, s.charCodeAt(2), s.charCodeAt(3), th_a, th_b);
        return r;
    };
    cowconfig_rule.prototype.toPayload = function () {
        return String.fromCharCode(this.address & 0xFF) + String.fromCharCode((this.address >> 8) & 0xFF) + String.fromCharCode(this.operation) + String.fromCharCode(this.action) + String.fromCharCode(this.threshold_a & 0xFF) + String.fromCharCode((this.threshold_a >> 8) & 0xFF) + String.fromCharCode(this.threshold_b & 0xFF) + String.fromCharCode((this.threshold_b >> 8) & 0xFF);
    };
    return cowconfig_rule;
})();
var cowconfig_packet = (function () {
    function cowconfig_packet(new_id, new_method, new_rule) {
        if (new_id === void 0) { new_id = 0; }
        if (new_method === void 0) { new_method = 0 /* CCPM_LIST */; }
        if (new_rule === void 0) { new_rule = null; }
        this.id = new_id;
        this.method = new_method;
        this.rule = new_rule;
    }
    cowconfig_packet.fromString = function (s) {
        var rule_string = s.substr(2, s.length - 2);
        var rule = cowconfig_rule.fromString(rule_string);
        var r = new cowconfig_packet(s.charCodeAt(0), s.charCodeAt(1), rule);
        return r;
    };
    cowconfig_packet.prototype.toCowpacket = function (address) {
        var payload = String.fromCharCode(this.id) + String.fromCharCode(this.method) + ((this.rule) ? this.rule.toPayload() : "");
        return new cowpacket(cowpacket.COWBUS_VERSION, getNextSeqNo(), cowpacket.DEFAULT_TTL, address, 7 /* configure */, false, btoa(payload));
    };
    return cowconfig_packet;
})();
var cowconfig_rule_pool = (function () {
    function cowconfig_rule_pool() {
    }
    cowconfig_rule_pool.init = function () {
        cowconfig_rule_pool.pool = [];
    };
    cowconfig_rule_pool.add = function (node_address, id, r) {
        if (!(cowconfig_rule_pool.pool[node_address])) {
            cowconfig_rule_pool.pool[node_address] = [];
        }
        cowconfig_rule_pool.pool[node_address][id] = r;
        console.log(cowconfig_rule_pool.pool);
        updateRuleList(node_address); // GUI
    };
    cowconfig_rule_pool.get_by_node = function (node_address) {
        var rules = [];
        if (cowconfig_rule_pool.pool[node_address]) {
            for (var i = 0; i < cowconfig_rule_pool.pool[node_address].length; ++i) {
                rules[i] = cowconfig_rule_pool.pool[node_address][i];
            }
        }
        return rules;
    };
    cowconfig_rule_pool.delete_one = function (node_address, id) {
        if (!(cowconfig_rule_pool.pool[node_address]) || !(cowconfig_rule_pool.pool[node_address][id])) {
            return;
        }
        cowconfig_rule_pool.pool[node_address][id] = undefined;
        var pkt = new cowconfig_packet(id, 3 /* CCPM_DELETE_ONE */, null);
        var cpkt = pkt.toCowpacket(node_address);
        sock.send(cpkt.generateJSON());
        updateRuleList(node_address); // GUI
    };
    cowconfig_rule_pool.delete_all = function (node_address) {
        if (!(cowconfig_rule_pool.pool[node_address])) {
            return;
        }
        cowconfig_rule_pool.pool[node_address] = undefined;
        var pkt = new cowconfig_packet(0, 2 /* CCPM_DELETE_ALL */, null);
        var cpkt = pkt.toCowpacket(node_address);
        sock.send(cpkt.generateJSON());
        updateRuleList(node_address); // GUI
    };
    return cowconfig_rule_pool;
})();
