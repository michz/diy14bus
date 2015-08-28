var cow = (function () {
    function cow(new_address, new_name) {
        if (new_name === void 0) { new_name = cow.UNKNOWN_NAME; }
        this.address = new_address;
        this.name = new_name;
        console.log("Constructing cow with name " + new_name);
        // TODO ping for configuration
    }
    cow.fromPacket = function (pkt) {
        var c = new cow(pkt.address);
        if (pkt.type == 7 /* ping_answer */) {
            logme("Received ping answer from " + pkt.address + " (" + pkt.payload + ")", 'success');
        }
        if ((pkt.type == 3 /* get_name */ || pkt.type == 7 /* ping_answer */) && pkt.payload.length > 0) {
            c.name = pkt.payload;
        }
        return c;
    };
    cow.UNKNOWN_NAME = "&lt;unknown&gt;";
    return cow;
})();
