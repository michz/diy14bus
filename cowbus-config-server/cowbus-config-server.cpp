#include <set>
#include <string>
#include <getopt.h>
#include <cstdlib>
#include <sstream>
#include <iostream>

#include <signal.h>
#include <unistd.h>

#include <boost/thread.hpp>

#include "../cowbus/include/cowpacket.h"
#include "ws_server.h"
#include "nrf_server.h"
#include "base64.h"

#define RAPIDJSON_ASSERT(x) 

#include "rapidjson/document.h"


static ws_server*  ws_inst;
static nrf_server* nrf_inst;

using namespace std;
using boost::thread;

void my_handler(int s){
    printf("Caught signal %d. Shutting down sockets and stopping.\n", s);

    ws_inst->stop();
    nrf_inst->stop();

    exit(1);
}

void ws_packet_handler(string data) {
    cout << "CLIENT -> SERVER: " << data << endl;

    rapidjson::Document d;
    d.Parse<0>(data.c_str());

    char tx_buf[sizeof(cowpacket)];
    memset(tx_buf, 0, sizeof(cowpacket));

    /* fill TX buffer with data */
    cowpacket* cp = (cowpacket*)tx_buf;

    cp->version = d["version"].GetInt();
    cp->seq_no  = d["seq_no"].GetInt();
    cp->ttl     = d["ttl"].GetInt();
    cowpacket_set_address(cp, (uint16_t)(d["address"].GetInt()));
    cowpacket_set_type(cp, static_cast<cowpacket_type>(d["type"].GetInt()));
    cowpacket_set_is_fragment(cp, 0);

    cout << "DEBUG Addr: " << cowpacket_get_address(cp) << endl;
    cout << "DEBUG TTL : " << cp->ttl << endl;
    cout << "DEBUG Type: " << cowpacket_get_type(cp) << endl;

    string payload_s = base64_decode(d["payload"].GetString());
    int payload_length = payload_s.length();
    const char* payload = payload_s.c_str();

    cout << "Payload: " << payload << endl;
    memset(cp->payload, 0, PAYLOAD_MAX_LENGTH);
    memcpy(cp->payload, payload, payload_length);

    //cowpacket_generate_checksum(cp);

    nrf_inst->sendMessage(tx_buf);
}

void nrf_packet_handler(string data) {
    cout << "SERVER <- RADIO: " << data << endl;
    cout << "CLIENT <- SERVER" << endl;
            
    ws_inst->send(data);
}

int main( int argc, char ** argv) {
    // register signals
    struct sigaction sigIntHandler;

    sigIntHandler.sa_handler = my_handler;
    sigemptyset(&sigIntHandler.sa_mask);
    sigIntHandler.sa_flags = 0;

    sigaction(SIGINT, &sigIntHandler, NULL);


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
