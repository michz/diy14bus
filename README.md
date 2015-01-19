diy14bus
========


Getting started
---------------
Please read [Erste (Repository-)Schritte](http://michz.github.io/diy14bus/2014/12/Erste-Repo-Schritte/) (german).

Short version in english:
Please make sure that you have cloned
[our RIOT fork](https://github.com/patkan/RIOT) on the same directory level.

Example:

    /home/user/home-project/diy14bus/   # this repository
    /home/user/home-project/RIOT/       # patkan/RIOT


For compiling arm based binaries you need a fully functional arm-gcc toolchain.
We use [gcc-arm-embedded](https://launchpad.net/~terry.guo/+archive/ubuntu/gcc-arm-embedded).

If you want to run the configuration tool on a Raspberry Pi,
clone the
[RF24](https://github.com/edoardoo/RF24)-
Repository and the 
[WebsocketPP](https://github.com/zaphoyd/websocketpp.git)-
Repository into a directory on the same level as the above mentioned.

Your final directory structure should look like this:

    your_project_dir
    |--> diy14bus/
    |--> RIOT/
    |--> RF24/
    |--> websocketpp/


Compiling
---------
Go to application directory (for example `first-test/`) and run `make`.
(No need to build RIOT directly.)


Compiling cowbus-config-server
------------------------------
One special note about the config-server:
This tool depends on a Raspberry Pi and can be compiled there, and *only there*.
(Fancy crosscompiling voodoo possible...)

Before being able to compile cowbus-config-server, you have to compile and install
the RF24 library by changing to the directory RF24 and type:

    make install   # NOTE: perhaps you need sudo ...

This compiles the RF24 library and installs the binary system wide.

Moreover you need at least GCC version 4.7 or 4.8 (we use C++11 language features).



License
-------
We will think about it.
