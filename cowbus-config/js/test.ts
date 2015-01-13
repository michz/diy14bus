/// <reference path="lib/jquery.d.ts" />

function greeter(person: string) {
    return "Hello, " + person;
}

var user = "Jane User";


$(document).ready(function() {
    $("body").html(greeter(user));
});


// vim: set et ts=4 sw=4 syntax=javascript:
