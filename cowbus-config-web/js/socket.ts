class socket {

    wsUri       : string = "ws://piplus1:9002/";
    websocket   : WebSocket;

    constructor() {
        this.websocket              = new WebSocket(this.wsUri);
        this.websocket.onopen       = this.onOpen;
        this.websocket.onclose      = this.onClose;
        this.websocket.onmessage    = this.onMessage;
        this.websocket.onerror      = this.onError;
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
