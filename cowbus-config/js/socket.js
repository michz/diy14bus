var socket = (function () {
    function socket() {
        this.wsUri = "ws://piplus1:9002/";
        this.websocket = new WebSocket(this.wsUri);
        this.websocket.onopen = this.onOpen;
        this.websocket.onclose = this.onClose;
        this.websocket.onmessage = this.onMessage;
        this.websocket.onerror = this.onError;
    }
    socket.prototype.onOpen = function (evt) {
        logme("CONNECTED", "success");
    };
    socket.prototype.onClose = function (evt) {
        logme("DISCONNECTED", "error");
    };
    socket.prototype.onMessage = function (evt) {
        pktHandler(evt.data);
    };
    socket.prototype.onError = function (evt) {
        logme('<span style="color: red;">ERROR:</span> ' + evt.data, "error");
    };
    socket.prototype.send = function (message) {
        logme("SENT: " + message);
        this.websocket.send(message);
    };
    return socket;
})();
