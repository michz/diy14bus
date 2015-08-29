var cow = (function () {
    function cow(new_address, new_name) {
        if (new_name === void 0) { new_name = cow.UNKNOWN_NAME; }
        this.address = new_address;
        this.name = new_name;
    }
    cow.prototype.request_configuration = function () {
        // TODO timeouts/delays?
        var cow = this;
        // get_name request
        var pkt = new cowpacket(0, seqNo++, stdTtl, cow.address, 2 /* get_name */, false, btoa(""));
        sock.send(pkt.generateJSON());
        setTimeout(function () {
            var pkt2 = new cowpacket(0, seqNo++, stdTtl, cow.address, 7 /* configure */, false, btoa(String.fromCharCode(0)));
            sock.send(pkt2.generateJSON());
        }, 100);
    };
    cow.fromPacket = function (pkt) {
        var c = new cow(pkt.address);
        if (pkt.type == 5 /* ping_answer */) {
            logme("Received ping answer from " + pkt.address + " (" + pkt.payload + ")", 'success');
        }
        if ((pkt.type == 2 /* get_name */ || pkt.type == 5 /* ping_answer */) && pkt.payload.length > 0) {
            c.name = pkt.payload;
        }
        return c;
    };
    cow.UNKNOWN_NAME = "&lt;unknown&gt;";
    return cow;
})();
