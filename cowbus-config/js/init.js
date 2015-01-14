$(document).ready(function () {
    initWebSocket();
});
function pktHandler(json) {
    var obj = JSON.parse(json);
    var pkt = cowpacket.fromJSON(obj);
    //logme(obj.payload);
    // TODO: irgendwas mit obj anfangen
}
function logme(msg, cls) {
    if (cls === void 0) { cls = ""; }
    $("#log-output").append("<p class='" + cls + "'>" + msg + "</p>");
}
