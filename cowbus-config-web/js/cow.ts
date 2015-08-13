class cow {
    address : number;
    name    : string;
    methods : string[];


    constructor(new_address : number, new_name : string = "unnamed") {
        this.address    = new_address;
        this.name       = new_name;
    }
    
    static fromPacket(pkt : cowpacket) : cow {
        var c = new cow(pkt.address);
        if (pkt.type == cowpacket_type.ping_answer) {
            logme("Received ping answer from " + pkt.address + " (" + pkt.payload + ")", 'success');
        }
        if ((pkt.type == cowpacket_type.get_name ||
            pkt.type == cowpacket_type.ping_answer) &&
            pkt.payload.length > 0) {
                c.name = pkt.payload;
        }
        return c;
    }
}


// vim: set et ts=4 sw=4 syntax=javascript:
