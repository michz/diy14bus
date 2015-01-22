var socket = (function () {
    function socket() {
    }
    socket.prototype.connect = function (addr) {
        logme("Trying to connect to WebSocket server under URI  " + addr);
        this.websocket = new WebSocket(addr);
        this.websocket.onopen = this.onOpen;
        this.websocket.onclose = this.onClose;
        this.websocket.onmessage = this.onMessage;
        this.websocket.onerror = this.onError;
    };
    socket.prototype.close = function () {
        this.websocket.close();
    };
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
