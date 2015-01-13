#include <set>
#include <string>
#include <getopt.h>
#include <cstdlib>
#include <sstream>
#include <iostream>

#include <boost/thread.hpp>

#include "../cowbus/cowpacket.h"
#include "ws_server.h"
#include "nrf_server.h"


using namespace std;

using boost::thread;



int main( int argc, char ** argv) {
    // Create a websocket server endpoint
    ws_server wss;
    boost::thread ws_thread(&ws_server::run, &wss, 9002);

    nrf_server nrfs;
    boost::thread nrf_thread(&nrf_server::run, &nrfs);

    // wait for websocketpp-server to terminate (should not happen)
    ws_thread.join();
}
