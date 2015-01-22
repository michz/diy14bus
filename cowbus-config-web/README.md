cowbus-config webapp
====================

General
-------

Simple web app for monitoring and configuring a cowbus network.

For stricter type-safe development we use
[TypeScript](http://www.typescriptlang.org/).
Please notice, that JavaScript files are generated automatically by the
TypeScript compiler and should *never be changed* manually and commited.

If you need "plain old JavaScript", please create a new file under

    js/legacy/

or think about switching to TypeScript.


Prerequisites
-------------
To run the webapp you need a running cowbus-config-server instance somewhere
accessible via TCP/IP and a modern web browser with WebSocket support and
activated JavaScript.
