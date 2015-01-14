var wsU

$(document).ready(function() {
    initWebSocket();
});

function pktHandler(json : string) {
    var obj = JSON.parse(json);
    logme(obj.payload);
    // TODO: irgendwas mit obj anfangen
}

function logme(msg : string, cls : string = "") {
    $("#log-output").append("<p class='" + cls + "'>" + msg  + "</p>");
}


// vim: set et ts=4 sw=4 syntax=javascript:
