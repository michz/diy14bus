enum cowpacket_type {
    undefined_packet    = 0,
    event_packet        = 1,
    program             = 2,
    get_name            = 3,
    get_state           = 4,
    get_config          = 5,
    ping                = 6,
    ping_answer         = 7
}
class cowpacket {
    version : number;
    seq_no  : number;
    ttl     : number;
    address : number;
    type    : cowpacket_type;
    is_fragment: boolean;
    payload : string;

    constructor(new_version: number = 0, new_seq_no: number = 1, 
                new_ttl: number = 4, new_address: number = 2047,
                new_type: cowpacket_type = cowpacket_type.undefined_packet,
                new_is_fragment: boolean = false, new_payload: string = "") {
        this.version    = new_version;
        this.seq_no     = new_seq_no;
        this.ttl        = new_ttl;
        this.address    = new_address;
        this.type       = new_type;
        this.is_fragment = new_is_fragment;
        this.payload    = new_payload;
    }

    static fromJSON(json: Object) : cowpacket {
        var r = new cowpacket(
            json['version'],
            json['seq_no'],
            json['ttl'],
            json['address'],
            json['type'],
            json['is_fragment'],
            json['payload']
            );
        return r;
    }

    generateJSON() : string {
        return JSON.stringify(this);
    }
}



// vim: set et ts=4 sw=4 syntax=javascript:
