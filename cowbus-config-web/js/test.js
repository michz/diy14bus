/// <reference path="lib/jquery.d.ts" />
function greeter(person) {
    return "Hello, " + person;
}
var user = "Jane User";
$(document).ready(function () {
    $("body").html(greeter(user));
});
