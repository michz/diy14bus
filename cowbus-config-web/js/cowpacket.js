var cowpacket_type;
(function (cowpacket_type) {
    cowpacket_type[cowpacket_type["undefined_packet"] = 0] = "undefined_packet";
    cowpacket_type[cowpacket_type["event_packet"] = 1] = "event_packet";
    cowpacket_type[cowpacket_type["program"] = 2] = "program";
    cowpacket_type[cowpacket_type["get_name"] = 3] = "get_name";
    cowpacket_type[cowpacket_type["get_state"] = 4] = "get_state";
    cowpacket_type[cowpacket_type["get_config"] = 5] = "get_config";
    cowpacket_type[cowpacket_type["ping"] = 6] = "ping";
    cowpacket_type[cowpacket_type["ping_answer"] = 7] = "ping_answer";
    cowpacket_type[cowpacket_type["set_name"] = 8] = "set_name";
    cowpacket_type[cowpacket_type["configure"] = 9] = "configure";
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
        var r = new cowpacket(json['version'], json['seq_no'], json['ttl'], json['address'], json['type'], json['is_fragment'], atob(json['payload']));
        return r;
    };
    cowpacket.prototype.generateJSON = function () {
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
