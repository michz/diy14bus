/**
 *
 * @author TODO
 *
 * @file
 */

#ifndef NRF_SERVER_H
#define NRF_SERVER_H

#include <string>
#include <getopt.h>
#include <cstdlib>
#include <sstream>
#include <iostream>
//#include <RF24/RF24.h>
#include "../../RF24/RF24.h"

#include "ws_server.h"

#include "../cowbus/cowpacket.h"

class ws_server;

class nrf_server {
    public:
        /**
         * TODO
         */
        nrf_server() {
            //Prepare the radio module
            radio.begin();
            radio.setRetries(3, 3); // not used
            //	radio.setPALevel(RF24_PA_MAX);
            radio.setDataRate(RF24_250KBPS);
            radio.setChannel(5);
            radio.setPayloadSize(32);

            radio.printDetails(); // DEBUG
            radio.openWritingPipe(pipes[0]);
            radio.openReadingPipe(1, pipes[1]);
            radio.setAutoAck(false);

            radio.startListening();
        }

        ~nrf_server() {
            radio.stopListening();
        }

        /**
         * TODO
         */
        bool sendMessage(std::string const payload){
            radio.stopListening(); //Stop listening

            std::cout << "Now sending  " << payload << std::endl;

            // Send the message
            bool ok = radio.write(payload.c_str(), sizeof(cowpacket));
            
            radio.startListening(); // resume listening operation
            
            if (!ok) {
                std::cout << "failed..." << std::endl;
                return false;
            } 
            return true;
        }

        /**
         * TODO
         */
        void run() {
            char read_buf[sizeof(cowpacket)];
            while(true) {
                if (radio.available()) {
                    radio.read(read_buf, sizeof(cowpacket));
                    cowpacket* cp = (cowpacket*)read_buf;

                    char payload[PAYLOAD_MAX_LENGTH+1];
                    payload[PAYLOAD_MAX_LENGTH] = 0;
                    memcpy(payload, cp->payload, PAYLOAD_MAX_LENGTH);

                    printf("seq_no: %d\n", cp->seq_no);
                    printf("TTL   : %d\n", cp->ttl);
                    printf("addr  : %d\n", cp->addr);
                    printf("type  : %d\n", cp->type);
                    printf("isFrag: %d\n", cp->is_fragment);
                    printf("data  : %s\n", payload);
                    printf("\n");

                    std::stringstream ss;
                    ss << "{ " <<
                        "\"seq_no\": \""    << cp->seq_no << "\", " <<
                        "\"ttl\": \""       << cp->ttl << "\", " <<
                        "\"address\": \""   << cp->addr << "\", " <<
                        "\"type\": \""      << cp->type << "\", " <<
                        "\"is_fragment\": \"" << cp->is_fragment << "\", " <<
                        "\"payload\": \""   << payload << "\" " <<
                        " }";
                    std::cout << "Sending JSON to client: " << ss.str();
                    
                    to_ws->send(ss.str());
                }

                //TODO: Sleep-Time anpassen
                boost::this_thread::sleep(boost::posix_time::milliseconds(10));
            }
        }

        /**
         * TODO
         */
        void set_to_ws(ws_server* callback) {
            to_ws = callback;
        }


        /**
         * TODO
         */
        void send_json(const std::string & data) {
            //TODO: JSON parsen und Daten in cowpacket packen
        }

    private:
        RF24 radio{RPI_V2_GPIO_P1_22, RPI_V2_GPIO_P1_24, BCM2835_SPI_SPEED_8MHZ};
        const uint64_t pipes[2] = { 0xe7e7e7e7e7LL, 0xe7e7e7e7e7LL };
        ws_server*  to_ws;
};


#endif  // NRF_SERVER_H
