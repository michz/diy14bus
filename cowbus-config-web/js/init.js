/// <reference path="lib/jquery.d.ts" />
/// <reference path="lib/jqueryui.d.ts" />
var known_cows = new cowList();
var sock;
var seqNo = 1;
var stdTtl = 5;
$(document).ready(function () {
    sock = new socket();
    // make first dialog button to standard button (called when ENTER pressed)
    // src of next 15 lines of code:   http://stackoverflow.com/a/868999
    $.extend($.ui.dialog.prototype.options, {
        create: function () {
            var $this = $(this);
            // focus first button and bind enter to it
            $this.parent().find('.ui-dialog-buttonpane button:first').focus();
            $this.keypress(function (e) {
                if (e.keyCode == $.ui.keyCode.ENTER) {
                    $this.parent().find('.ui-dialog-buttonpane button:first').click();
                    return false;
                }
            });
        }
    });
    // init rename dialog
    $("#dialog-rename").dialog({
        autoOpen: false,
        width: 400,
        modal: true,
        buttons: [
            {
                text: "OK",
                click: function () {
                    var addr = $("#hidRenameAddr").val();
                    var name = $("#txtRename").val();
                    logme("Rename address " + addr + " to " + name);
                    var pkt = new cowpacket(0, seqNo++, stdTtl, addr, 8 /* set_name */, false, name);
                    sock.send(pkt.generateJSON());
                    $(this).dialog("close");
                }
            },
            {
                text: "Cancel",
                click: function () {
                    $(this).dialog("close");
                }
            }
        ]
    });
});
function pktHandler(json) {
    var obj = JSON.parse(json);
    var pkt = cowpacket.fromJSON(obj);
    logme("Received: " + JSON.stringify(pkt));
    known_cows.updateCow(cow.fromPacket(pkt));
    // TODO: irgendwas mit obj anfangen
}
function logme(msg, cls) {
    if (cls === void 0) { cls = ""; }
    $("#log-output").append("<p class='" + cls + "'>" + msg + "</p>");
}
function showRenameDialog() {
}
