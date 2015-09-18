/// <reference path="lib/jquery.d.ts" />
/// <reference path="lib/jqueryui.d.ts" />

var known_cows  : cowList   = new cowList();
var sock        : socket;
var seqNo       : number    = 1;
var stdTtl      : number    = 5;

$(document).ready(function() {
    sock = new socket();
    cowconfig_rule_pool.init();

    // make first dialog button to standard button (called when ENTER pressed)
    // src of next 15 lines of code:   http://stackoverflow.com/a/868999
    $.extend($.ui.dialog.prototype.options, { 
        create: function() {
            var $this = $(this);

            // focus first button and bind enter to it
            $this.parent().find('.ui-dialog-buttonpane button:first').focus();
            $this.keypress(function(e) {
                if( e.keyCode == $.ui.keyCode.ENTER ) {
                    $this.parent().find('.ui-dialog-buttonpane button:first').click();
                    return false;
                }
            });
        } 
    });

    // init connect dialog
    $( "#dialog-connect" ).dialog({
        autoOpen: false,
        width: 500,
        modal: true,
        buttons: [
            {
                text: "Connect",
                click: function() {
                    var addr = $("#txtHost").val();
                    store.setHost(addr);
                    sock.connect("ws://" + addr + "/");
                    $( this ).dialog( "close" );
                }
            }
        ]
    });
    $("#txtHost").val(store.getHost());
    $("#btnClose").click(function() { $("#dialog-connect").dialog("open"); });
    
    $("#btnScan").click(function() { known_cows.scan(); });
    $("#btnClear").click(function() { $("#log-output").empty(); });

    // init rename dialog
    $( "#dialog-rename" ).dialog({
        autoOpen: false,
        width: 400,
        modal: true,
        buttons: [
            {
                text: "OK",
                click: function() {
                    var addr = $("#hidRenameAddr").val();
                    var name = $("#txtRename").val();

                    logme("Rename address " + addr + " to " + name);

                    var pkt = new cowpacket(0, getNextSeqNo(), stdTtl, addr,
                        cowpacket_type.set_name, false, btoa(name));

                    sock.send(pkt.generateJSON());

                    $( this ).dialog( "close" );
                }
            },
            {
                text: "Cancel",
                click: function() {
                    $( this ).dialog( "close" );
                }
            }
        ]
    });

    // init config dialog
    $( "#dialog-config" ).dialog({
        autoOpen: false,
        width: 700,
        modal: true,
        open: function() {
            var addr = $("#hidCfgAddr").val();
            updateRuleList(addr);
        },
        buttons: [
            {
                text: "OK",
                click: function() {
                    var node_addr = $("#hidCfgAddr").val();
                    var addr = parseInt($("#txtCfgSourceAddress").val());
                    var op = parseInt($("#selCfgOperation").val());
                    var thresh_a = parseInt($("#txtCfgThresholdA").val());
                    var thresh_b = parseInt($("#txtCfgThresholdB").val());
                    var action = parseInt($("#txtCfgAction").val());

                    // validate input
                    if (!$.isNumeric(addr) || addr < 1 || addr > 65534) {
                        alert("addr must be an integer number and greater than 0 and smaller than 65535.");
                        return false;
                    }
                    if (!$.isNumeric(thresh_a) || thresh_a < 0) {
                        alert("threshold_a must be a positive integer number and smaller than 65535.");
                        return false;
                    }
                    if (op >= 8 && !$.isNumeric(thresh_b) || thresh_a < 0) {
                        alert("threshold_b must be a positive integer number and smaller than 65535.");
                        return false;
                    }
                    if (thresh_b <= thresh_a) {
                        alert("threshold_b must be larger than threshold_a!");
                        return false;
                    }
                    if (!$.isNumeric(action) || action < 0 || action > 127) {
                        alert("action must be a positive integer number and smaller than 128.");
                        return false;
                    }

                    // TODO own class for cowconfig_rule, cowconfig_packet
                    var cfg_string =    String.fromCharCode(0) +
                                        String.fromCharCode(1) + 
                                        String.fromCharCode(addr & 0xFF) + 
                                        String.fromCharCode((addr >> 8) & 0xFF) + 
                                        String.fromCharCode(op) + 
                                        String.fromCharCode(action) +
                                        String.fromCharCode((thresh_a)      & 0xFF) + 
                                        String.fromCharCode((thresh_a >> 8) & 0xFF) + 
                                        String.fromCharCode((thresh_b)      & 0xFF) +
                                        String.fromCharCode((thresh_b >> 8) & 0xFF); 

                    var pkt = new cowpacket(0, getNextSeqNo(), stdTtl, node_addr,
                        cowpacket_type.configure, false, btoa(cfg_string));

                    sock.send(pkt.generateJSON());

                    $( this ).dialog( "close" );
                }
            },
            {
                text: "Cancel",
                click: function() {
                    $( this ).dialog( "close" );
                }
            },
            {
                text: "Delete all rules",
                click: function() {
                    var node_addr = parseInt($("#hidCfgAddr").val());
                    cowconfig_rule_pool.delete_all(node_addr);
                }
            }
        ]
    });



    // and now start
    $("#dialog-connect").dialog("open");

    //    window.setInterval(known_cows.scan, 5000);

    // debug
    //known_cows.updateCow(new cow(2))
});

function pktHandler(json : string) {
    var obj = JSON.parse(json);
    logme("Received: " + JSON.stringify(obj));
    var pkt = cowpacket.fromJSON(obj);
    known_cows.updateCow(cow.fromPacket(pkt));
    if (pkt.type == cowpacket_type.configure) {
        var cfgpkt = cowconfig_packet.fromString(pkt.payload);
        logme("Config received: " + JSON.stringify(cfgpkt), 'success');
        cowconfig_rule_pool.add(pkt.address, cfgpkt.id, cfgpkt.rule);
        known_cows.updateView();
    }
}

function logme(msg : string, cls : string = "") {
    $("#log-output").append("<p class='" + cls + "'>" + msg  + "</p>");
    $("#right").animate({scrollTop: $("#log-output").height()}, "slow");
}

function showRenameDialog() {
}

function updateRuleList(addr) {
    var rules = cowconfig_rule_pool.get_by_node(addr);
    console.log("Loading rules for dialog for addr " + addr + ": ");
    console.log(rules);

    $("#cfg-right").empty();

    for (var i = 0; i < rules.length; ++i) {
        var r = rules[i];
        if (!r) continue;
        $("#cfg-right").append(
            '<div class="cfg-rule">' +
            '    <p><span class="config-label">ID: ' + i + '</span></p>' +
            '    <p><span class="config-label">Adresse: ' + r.address + '</span></p>' +
            '    <p><span class="config-label">Operation: ' + r.operation + '</span></p>' +
            '    <p><span class="config-label">Action: ' + r.action + '</span></p>' +
            '    <p><span class="config-label">Threshold A: ' + r.threshold_a + '</span></p>' +
            '    <p><span class="config-label">Threshold B: ' + r.threshold_b + '</span></p>' +
            '    <span onclick="deleteConfigRule('+addr+', '+i+')">Delete rule</span>' +
            '</div>' 
        );
    }

    known_cows.updateView();
}

function deleteConfigRule(addr, id) : void {
    cowconfig_rule_pool.delete_one(addr, id);
}

function getNextSeqNo() : number {
    seqNo++;
    if (seqNo > 30) seqNo = 0;

    return seqNo;
}


// vim: set et ts=4 sw=4 syntax=javascript:
