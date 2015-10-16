enum cowpacket_type {
    undefined_packet    = 0,
    event_packet        = 1,
    get_name            = 2,
    get_state           = 3,
    ping                = 4,
    ping_answer         = 5,
    set_name            = 6,
    configure           = 7,
    error               = 14,
    ack                 = 15
}
class cowpacket {
    public static COWBUS_VERSION  : number = 0;
    public static DEFAULT_TTL     : number = 4;

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
            parseInt(json['version']),
            parseInt(json['seq_no']),
            parseInt(json['ttl']),
            parseInt(json['address']),
            json['type'],
            json['is_fragment'],
            atob(json['payload'])
            );
        return r;
    }

    generateJSON() : string {
        if (typeof this.address == "string") this.address = parseInt(<any>this.address);
        if (typeof this.ttl == "string") this.ttl = parseInt(<any>this.ttl);
        if (typeof this.version == "string") this.version = parseInt(<any>this.version);
        if (typeof this.seq_no == "string") this.seq_no = parseInt(<any>this.seq_no);
            
        if (typeof this.is_fragment == "string") {
            this.is_fragment = (<any>this.is_fragment == "1") ? true : false;
        }
        return JSON.stringify(this);
    }
    
    getRawByte(i : number) : number {
        if (this.payload.length <= i) {
            logme("Error in cowpacket::getRawByte(i : number): String short than i.", 'error');
            return -1;
        }
        return this.payload.charCodeAt(i);
    }
}



// vim: set et ts=4 sw=4 syntax=javascript:
