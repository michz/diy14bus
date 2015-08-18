var cowList = (function () {
    function cowList() {
        this.cows = new Array();
    }
    cowList.prototype.updateCow = function (new_cow) {
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
        }
        console.log(this.cows);
        // update display
        this.updateView();
    };
    cowList.prototype.updateView = function () {
        $("#nodes").children().remove();
        for (var i = 0; i < this.cows.length; i++) {
            var c = this.cows[i];
            $("#nodes").append('<div class="node" id="node_' + i + '">' + '    <h3 id="node_' + i + '_name">' + c.name + '</h3>' + '    <span class="addr" id="node_' + i + '_addr">' + c.address + '</span>' + '    <p class="buttons">' + '        <span class="node-button button-config" ' + 'title="Config" id="node_' + i + '_config">Config</span>' + '        <span class="node-button button-rename" ' + 'title="Rename" id="node_' + i + '_rename">Rename</span>' + '        <span class="node-button button-ping" title="ping" ' + 'id="node_' + i + '_ping">Ping</span>' + '    </p>' + '    <p style="clear:both;"></p>' + '</div>');
            $('#node_' + i + '_config').button({
                icons: { primary: " ui-icon-wrench" },
                text: false
            }).on('click', function (event) {
                $("#hidCfgAddr").val(String(c.address));
                $("#txtCfgSourceAddrress").val("");
                $("#selCfgOperation").val("");
                $("#txtCfgThresholdA").val("");
                $("#txtCfgThresholdB").val("");
                $("#txtCfgAction").val("");
                $("#dialog-config").dialog("open");
                $("#selCfgOperation").select();
                event.preventDefault();
            });
            $('#node_' + i + '_rename').button({
                icons: { primary: " ui-icon-pencil" },
                text: false
            }).on('click', function (event) {
                $("#hidRenameAddr").val(String(c.address));
                $("#spanRenameAddr").text(String(c.address));
                $("#txtRename").val(c.name);
                $("#dialog-rename").dialog("open");
                $("#txtRename").select();
                event.preventDefault();
            });
            $('#node_' + i + '_ping').button({
                icons: { primary: "ui-icon-signal-diag" },
                text: false
            }).on('click', function (event) {
                var pkt = new cowpacket(0, seqNo++, stdTtl, c.address, 6 /* ping */, false, name);
                sock.send(pkt.generateJSON());
                setTimeout(function () {
                    var pkt2 = new cowpacket(0, seqNo++, stdTtl, c.address, 9 /* configure */, false, btoa(String.fromCharCode(0)));
                    sock.send(pkt2.generateJSON());
                }, 100);
                event.preventDefault();
            });
        }
    };
    return cowList;
})();
