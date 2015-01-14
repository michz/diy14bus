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
    crc     : string;
}



// vim: set et ts=4 sw=4 syntax=javascript:
