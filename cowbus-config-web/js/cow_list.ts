class cowList {
    cows : Array<cow> = new Array<cow>();

    constructor() {
    }

    updateCow(new_cow : cow) : void {
        var updated = false;
        
        for (var i = 0; i < this.cows.length; i++) {
            var c = this.cows[i];

            if (c.address == new_cow.address) {
                updated = true;
    
                if (new_cow.name != cow.UNKNOWN_NAME) {
                    c.name = new_cow.name;
                }
            }
        }

        // not found in list, so create new entry
        if (!updated) {
            this.cows.push(new_cow);
            new_cow.request_configuration(); // ping for configuration
        }
        console.log(this.cows);

        // update display
        this.updateView();
    }
    
    scan() : void {
        var pkt = new cowpacket(0, seqNo++, stdTtl, 0,
            cowpacket_type.ping, false, "");
        sock.send(pkt.generateJSON());
    }

    updateView() : void {
        $("#nodes").children().remove();
        for (var i = 0; i < this.cows.length; i++) {
            var c = this.cows[i];
            var rules = cowconfig_rule_pool.get_by_node(c.address);
            var rules_count = 0;
            for (var j = 0; j < rules.length; ++j) {
                if (!rules[j]) continue;
                rules_count++;
            }
            var text = "Regeln: " + rules_count;
            $("#nodes").append(
                '<div class="node" id="node_' + i + '" data-node="' + i + '">' +
                '    <h3 id="node_' + i + '_name">' + c.name + '</h3>' +
                '    <span class="addr" id="node_' + i + '_addr">' +
                    c.address + '</span>' +
                '    <p class="buttons">' +
                '        <span class="node-button button-config" ' + 
                            'title="Config" id="node_' + i + '_config">Config</span>' +
                '        <span class="node-button button-rename" ' + 
                            'title="Rename" id="node_' + i + '_rename">Rename</span>' +
                '        <span class="node-button button-ping" title="ping" ' + 
                            'id="node_' + i + '_ping">Ping</span>' +
                '        <span class="node-text" ' + 
                            'id="node_' + i + '_text">' + text + '</span>' +
                '    </p>' +
                '    <p style="clear:both;"></p>' +
                '</div>'
            );


            $('#node_' + i + '_config').button({
                    icons: { primary: " ui-icon-wrench" },
                    text: false
                }).on('click', function(event) {
                    $("#hidCfgAddr").val(String(c.address));
                    $("#txtCfgSourceAddrress").val("");
                    $("#selCfgOperation").val("");
                    $("#txtCfgThresholdA").val("");
                    $("#txtCfgThresholdB").val("");
                    $("#txtCfgAction").val("");

                    $("#dialog-config").dialog( "open" );
                    $("#selCfgOperation").select();
                    event.preventDefault();
                    
            });

            $('#node_' + i + '_rename').button({
                    icons: { primary: " ui-icon-pencil" },
                    text: false
                }).on('click', function(event) {
                    $("#hidRenameAddr").val(String(c.address));
                    $("#spanRenameAddr").text(String(c.address));
                    $("#txtRename").val(c.name);
                    $("#dialog-rename").dialog( "open" );
                    $("#txtRename").select();
                    event.preventDefault();
                });
                
            $('#node_' + i + '_ping').button({
                    icons: { primary: "ui-icon-signal-diag" },
                    text: false
                }).on('click', function(event) {
                    var c = known_cows.cows[$(this).parent().parent().data("node")];
                    var pkt = new cowpacket(0, seqNo++, stdTtl, c.address,
                        cowpacket_type.ping, false, name);
                    sock.send(pkt.generateJSON());
                    
                    setTimeout(function() {
                        var pkt2 = new cowpacket(0, seqNo++, stdTtl, c.address,
                            cowpacket_type.configure, false, btoa(String.fromCharCode(0)));
                        sock.send(pkt2.generateJSON());
                    }, 100);

                    event.preventDefault();
                });
        }
    }
}


// vim: set et ts=4 sw=4 syntax=javascript:
