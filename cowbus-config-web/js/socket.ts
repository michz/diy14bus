class socket {

    websocket   : WebSocket;

    constructor() {
    }

    connect(addr : string) : void {
        logme("Trying to connect to WebSocket server under URI  " + addr);
        this.websocket              = new WebSocket(addr);
        this.websocket.onopen       = this.onOpen;
        this.websocket.onclose      = this.onClose;
        this.websocket.onmessage    = this.onMessage;
        this.websocket.onerror      = this.onError;
    }
    
    close() : void {
        this.websocket.close();
    }

    onOpen(evt) : void {
        logme("CONNECTED", "success");
    }

    onClose(evt) : void {
        logme("DISCONNECTED", "error");
    }

    onMessage(evt) : void {
        pktHandler(evt.data);
    }

    onError(evt) : void {
        logme('<span style="color: red;">ERROR:</span> ' + evt.data, "error");
    }

    send(message : string) : void {
        logme("SENT: " + message);
        this.websocket.send(message);
    }



}


// vim: set et ts=4 sw=4 syntax=javascript:
