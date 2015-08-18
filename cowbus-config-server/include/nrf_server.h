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
#include "RF24.h"
#include "base64.h"

#include "../../cowbus/include/cowpacket.h"

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

        void stop(void) {
            radio.stopListening();
        }

        /**
         * TODO
         */
        bool sendMessage(char* const payload){
            radio.stopListening(); //Stop listening

            // Send the message
            bool ok = radio.write(payload, sizeof(cowpacket));
            boost::this_thread::sleep(boost::posix_time::milliseconds(2));
            
            radio.startListening(); // resume listening operation
            
            if (!ok) {
                std::cout << "failed..." << std::endl;
                return false;
            }

            std::cout << "SERVER -> RADIO: " << std::endl;
            for (unsigned int i = 0; i < sizeof(cowpacket); ++i) {
                std::cout << (int)(payload[i]) << " ";
            }
            std::cout << std::endl;
            return true;
        }

        /**
         * TODO
         */
        void run() {
            char read_buf[sizeof(cowpacket)];
            memset(read_buf, 0, sizeof(cowpacket));
            while(true) {
                if (radio.available()) {
                    radio.read(read_buf, sizeof(cowpacket));
                    cowpacket* cp = (cowpacket*)read_buf;

                    if (cowpacket_check_checksum(cp)) {
                        unsigned char payload[PAYLOAD_MAX_LENGTH+1];
                        payload[PAYLOAD_MAX_LENGTH] = 0;
                        memcpy(payload, cp->payload, PAYLOAD_MAX_LENGTH);
                        std::cout << "Payload max length: " << PAYLOAD_MAX_LENGTH << std::endl;
                        std::cout << "Payload struct length: " << sizeof(payload) << std::endl;
                        for (int i = 0; i < PAYLOAD_MAX_LENGTH; ++i) {
                            std::cout << (int)(payload[i]) << " ";
                        }
                        std::cout << std::endl;

                        // transform payload to base64 to preserve null bytes etc.
                        std::string payload_base64 = base64_encode(payload, PAYLOAD_MAX_LENGTH);
                        std::stringstream ss;
                        ss << "{ " <<
                            "\"version\": \""   << cp->version << "\", " <<
                            "\"seq_no\": \""    << cp->seq_no << "\", " <<
                            "\"ttl\": \""       << cp->ttl << "\", " <<
                            "\"address\": \""   << cp->addr << "\", " <<
                            "\"type\": \""      << cp->type << "\", " <<
                            "\"is_fragment\": \"" << cp->is_fragment << "\", " <<
                            "\"payload\": \""   << payload_base64 << "\" " <<
                            " }";
                        
                        pkt_callback(ss.str());
                    }
                    else {
                        std::cerr << "Got corrupt packet." << std::endl;
                    }
                }

                //TODO: Sleep-Time anpassen
                boost::this_thread::sleep(boost::posix_time::microseconds(100));
            }
        }

        /**
         * @brief Set which function is called when a packet is received from radio.
         */
        void set_pkt_callback(void (*callback)(std::string)) {
            pkt_callback = callback;
        }

    private:
        RF24 radio{RPI_V2_GPIO_P1_22, RPI_V2_GPIO_P1_24, BCM2835_SPI_SPEED_8MHZ};
        const uint64_t pipes[2] = { 0xe7e7e7e7e7LL, 0xe7e7e7e7e7LL };
        void (*pkt_callback)(std::string);
};


#endif  // NRF_SERVER_H
