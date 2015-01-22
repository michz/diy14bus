var store = (function () {
    function store() {
    }
    store.check = function () {
        if (typeof (Storage) !== "undefined") {
            return true;
        }
        else {
            return false;
        }
    };
    store.getHost = function () {
        if (!this.check())
            return "piplus1:9002";
        var val = localStorage.getItem("host");
        if (val === null)
            return "piplus1:9002";
        return val;
    };
    store.setHost = function (val) {
        if (!this.check())
            return;
        localStorage.setItem("host", val);
    };
    return store;
})();
