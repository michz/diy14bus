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
})(cowpacket_type || (cowpacket_type = {}));
var cowpacket = (function () {
    function cowpacket() {
    }
    return cowpacket;
})();
