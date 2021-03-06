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
    
                if (new_cow.name != "unnamed") {
                    c.name = new_cow.name;
                }
            }
        }

        // not found in list, so create new entry
        if (!updated) {
            this.cows.push(new_cow);
        }
        console.log(this.cows);

        // update display
        this.updateView();
    }

    updateView() : void {
        $("#nodes").children().remove();
        for (var i = 0; i < this.cows.length; i++) {
            var c = this.cows[i];
            $("#nodes").append(
                '<div class="node" id="node_' + i + '">' +
                '    <h3 id="node_' + i + '_name">' + c.name + '</h3>' +
                '    <span class="addr" id="node_' + i + '_addr">' +
                    c.address + '</span>' +
                '    <p class="buttons">' +
                '        <span class="node-button button-rename" ' + 
                            'title="Rename" id="node_' + i + '_rename">Rename</span>' +
                '        <span class="node-button button-ping" title="ping" ' + 
                            'id="node_' + i + '_ping">Ping</span>' +
                '    </p>' +
                '    <p style="clear:both;"></p>' +
                '</div>'
            );

            $('#node_' + i + '_rename').click(function( event ) {
                $("#hidRenameAddr").val(String(c.address));
                $("#spanRenameAddr").text(String(c.address));
                $("#txtRename").val(c.name);
                $("#dialog-rename").dialog( "open" );
                $("#txtRename").select();
                event.preventDefault();
            });
            $('#node_' + i + '_ping').click(function( event ) {
                var pkt = new cowpacket(0, seqNo++, stdTtl, c.address,
                    cowpacket_type.ping, false, name);

                sock.send(pkt.generateJSON());
                event.preventDefault();
            });

            $('#node_' + i + '_rename').button({
                icons: { primary: " ui-icon-pencil" },
                text: false
            });
            $('#node_' + i + '_ping').button({
                icons: { primary: "ui-icon-signal-diag" },
                text: false
            });
        }
    }
}


// vim: set et ts=4 sw=4 syntax=javascript:
