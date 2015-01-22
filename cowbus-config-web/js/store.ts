class store {

    static check() : boolean {
        if(typeof(Storage) !== "undefined") {
            return true;
        } else {
            return false;
        }
    }

    static getHost() : string {
        if (!this.check()) return "piplus1:9002";

        var val = localStorage.getItem("host");
        if (val === null) return "piplus1:9002";
        return val;
    }
    
    static setHost(val : string) : void {
        if (!this.check()) return;
        localStorage.setItem("host", val);
    }



}


// vim: set et ts=4 sw=4 syntax=javascript:

