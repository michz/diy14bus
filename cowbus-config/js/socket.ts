var wsUri = "ws://piplus1:9002/";
var websocket;

function initWebSocket()
{
    websocket = new WebSocket(wsUri);
    websocket.onopen = function(evt) { onOpen(evt) };
    websocket.onclose = function(evt) { onClose(evt) };
    websocket.onmessage = function(evt) { onMessage(evt) };
    websocket.onerror = function(evt) { onError(evt) };
}

function onOpen(evt)
{
    logme("CONNECTED", "success");
}

function onClose(evt)
{
    logme("DISCONNECTED", "error");
}

function onMessage(evt)
{
    pktHandler(evt.data);
}

function onError(evt)
{
    logme('<span style="color: red;">ERROR:</span> ' + evt.data, "error");
}

function doSend(message)
{
    logme("SENT: " + message);
    websocket.send(message);
}



// vim: set et ts=4 sw=4 syntax=javascript:
