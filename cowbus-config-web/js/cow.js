var cow = (function () {
    function cow(new_address, new_name) {
        if (new_name === void 0) { new_name = "unnamed"; }
        this.address = new_address;
        this.name = new_name;
    }
    cow.fromPacket = function (pkt) {
        var c = new cow(pkt.address);
        if (pkt.type == 3 /* get_name */ && pkt.payload.length > 0) {
            c.name = pkt.payload;
        }
        return c;
    };
    return cow;
})();
