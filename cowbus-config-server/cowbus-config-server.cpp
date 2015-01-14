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


static ws_server*  ws_inst;
static nrf_server* nrf_inst;

using namespace std;
using boost::thread;


void ws_packet_handler(string data) {
    //TODO JSON generieren, CRC generieren, ...
    cout << "Got JSON: " << data << endl;
}

void nrf_packet_handler(string data) {
    cout << "Sending JSON to client: " << data << endl;
    ws_inst->send(data);
}

int main( int argc, char ** argv) {
    // Create a websocket server endpoint
    ws_server wss;
    nrf_server nrfs;

    ws_inst = &wss;
    nrf_inst = &nrfs;

    // set callback functions
    wss.set_pkt_callback(&ws_packet_handler);
    nrfs.set_pkt_callback(&nrf_packet_handler);

    // run threads
    boost::thread ws_thread(&ws_server::run, &wss, 9002);
    boost::thread nrf_thread(&nrf_server::run, &nrfs);

    // wait for websocketpp-server to terminate
    // (should not happen, exit with CTRL+C)
    ws_thread.join();
    nrf_thread.join();

    return 0;
}
