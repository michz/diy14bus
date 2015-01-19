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
    };
    cowList.prototype.updateView = function () {
        $("#nodes").children().remove();
        for (var i = 0; i < this.cows.length; i++) {
            var c = this.cows[i];
            $("#nodes").append('<div class="node" id="node_' + i + '">' + '    <h3 id="node_' + i + '_name">' + c.name + '</h3>' + '    <span class="addr" id="node_' + i + '_addr">' + c.address + '</span>' + '    <p class="buttons">' + '        <span class="node-button button-rename" ' + 'title="Rename" id="node_' + i + '_rename">Rename</span>' + '        <span class="node-button button-ping" title="ping" ' + 'id="node_' + i + '_ping">Ping</span>' + '    </p>' + '    <p style="clear:both;"></p>' + '</div>');
            $('#node_' + i + '_rename').click(function (event) {
                $("#hidRenameAddr").val(String(c.address));
                $("#spanRenameAddr").text(String(c.address));
                $("#txtRename").val(c.name);
                $("#dialog-rename").dialog("open");
                $("#txtRename").select();
                event.preventDefault();
            });
        }
    };
    return cowList;
})();
