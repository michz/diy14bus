class cow {
    public static UNKNOWN_NAME : string = "&lt;unknown&gt;";

    address : number;
    name    : string;
    methods : string[];


    constructor(new_address : number, new_name : string = cow.UNKNOWN_NAME) {
        this.address    = new_address;
        this.name       = new_name;
    }

    request_configuration() : void {
        // TODO timeouts/delays?
        var cow = this;

        // get_name request
        var pkt = new cowpacket(0, seqNo++, stdTtl, cow.address,
            cowpacket_type.get_name, false, btoa(""));
        sock.send(pkt.generateJSON());
        
        setTimeout(function() {
            var pkt2 = new cowpacket(0, seqNo++, stdTtl, cow.address,
                cowpacket_type.configure, false, btoa(String.fromCharCode(0)));
            sock.send(pkt2.generateJSON());
        }, 100);
        
    }
    
    static fromPacket(pkt : cowpacket) : cow {
        var c = new cow(pkt.address);
        if (pkt.type == cowpacket_type.ping_answer) {
            logme("Received ping answer from " + pkt.address + " (" + pkt.payload + ")", 'success');
        }
        if ((pkt.type == cowpacket_type.get_name ||
            pkt.type == cowpacket_type.ping_answer) &&
            pkt.payload.length > 0) {
                c.name = pkt.payload.replace(/\0/g, '').trim();
        }
        return c;
    }
}


// vim: set et ts=4 sw=4 syntax=javascript:
