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
#include <RF24/RF24.h>

#include "../cowbus/cowpacket.h"

using namespace std;

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

            printf("Now sending  %s...", payload);

            // Send the message
            bool ok = radio.write(payload.c_str(), sizeof(cowpacket));
            
            radio.startListening(); // resume listening operation
            
            if (!ok) {
                printf("failed...\n\r");
                return false;
            } 
            return true;
        }

        /**
         * TODO
         */
        void run() {
            while(true) {
                if (radio.available()) {
                    radio.read(read_buf, sizeof(cowpacket));
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
                    //TODO: in JSON packen und per ws_server an clients schicken
                }

                //TODO: Sleep-Time anpassen
                boost::this_thread::sleep(boost::posix_time::milliseconds(10));
            }
        }

    private:
        RF24 radio(RPI_V2_GPIO_P1_22, RPI_V2_GPIO_P1_24, BCM2835_SPI_SPEED_8MHZ);
        const uint64_t pipes[2] = { 0xe7e7e7e7e7LL, 0xe7e7e7e7e7LL };
}


#endif  // NRF_SERVER_H
