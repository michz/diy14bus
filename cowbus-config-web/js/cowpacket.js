var cowpacket_type;
(function (cowpacket_type) {
    cowpacket_type[cowpacket_type["undefined_packet"] = 0] = "undefined_packet";
    cowpacket_type[cowpacket_type["event_packet"] = 1] = "event_packet";
    cowpacket_type[cowpacket_type["get_name"] = 2] = "get_name";
    cowpacket_type[cowpacket_type["get_state"] = 3] = "get_state";
    cowpacket_type[cowpacket_type["ping"] = 4] = "ping";
    cowpacket_type[cowpacket_type["ping_answer"] = 5] = "ping_answer";
    cowpacket_type[cowpacket_type["set_name"] = 6] = "set_name";
    cowpacket_type[cowpacket_type["configure"] = 7] = "configure";
    cowpacket_type[cowpacket_type["error"] = 14] = "error";
    cowpacket_type[cowpacket_type["ack"] = 15] = "ack";
})(cowpacket_type || (cowpacket_type = {}));
var cowpacket = (function () {
    function cowpacket(new_version, new_seq_no, new_ttl, new_address, new_type, new_is_fragment, new_payload) {
        if (new_version === void 0) { new_version = 0; }
        if (new_seq_no === void 0) { new_seq_no = 1; }
        if (new_ttl === void 0) { new_ttl = 4; }
        if (new_address === void 0) { new_address = 2047; }
        if (new_type === void 0) { new_type = 0 /* undefined_packet */; }
        if (new_is_fragment === void 0) { new_is_fragment = false; }
        if (new_payload === void 0) { new_payload = ""; }
        this.version = new_version;
        this.seq_no = new_seq_no;
        this.ttl = new_ttl;
        this.address = new_address;
        this.type = new_type;
        this.is_fragment = new_is_fragment;
        this.payload = new_payload;
    }
    cowpacket.fromJSON = function (json) {
        var r = new cowpacket(parseInt(json['version']), parseInt(json['seq_no']), parseInt(json['ttl']), parseInt(json['address']), json['type'], json['is_fragment'], atob(json['payload']));
        return r;
    };
    cowpacket.prototype.generateJSON = function () {
        if (typeof this.address == "string")
            this.address = parseInt(this.address);
        if (typeof this.ttl == "string")
            this.ttl = parseInt(this.ttl);
        if (typeof this.version == "string")
            this.version = parseInt(this.version);
        if (typeof this.seq_no == "string")
            this.seq_no = parseInt(this.seq_no);
        if (typeof this.is_fragment == "string") {
            this.is_fragment = (this.is_fragment == "1") ? true : false;
        }
        return JSON.stringify(this);
    };
    cowpacket.prototype.getRawByte = function (i) {
        if (this.payload.length <= i) {
            logme("Error in cowpacket::getRawByte(i : number): String short than i.", 'error');
            return -1;
        }
        return this.payload.charCodeAt(i);
    };
    cowpacket.COWBUS_VERSION = 0;
    cowpacket.DEFAULT_TTL = 4;
    return cowpacket;
})();
