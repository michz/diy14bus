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
#include "../../cowbus/include/radio_config.h"


#if (RADIO_DATARATE == DR_250KBS)
#define RADIO_ON_AIR_FACTOR (8)
#elif (RADIO_DATARATE == DR_1MBS)
#define RADIO_ON_AIR_FACTOR (2)
#elif (RADIO_DATARATE == DR_2MBS)
#define RADIO_ON_AIR_FACTOR (1)
#endif

#define RADIO_ON_AIR_US     (RADIO_ON_AIR_FACTOR * 165)

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
#if (RADIO_DATARATE == DR_250KBS)
            radio.setDataRate(RF24_250KBPS);
#elif (RADIO_DATARATE == DR_1MBS)
            radio.setDataRate(RF24_1MBPS);
#elif (RADIO_DATARATE == DR_2MBS)
            radio.setDataRate(RF24_2MBPS);
#endif
            radio.setChannel(5);
            radio.setPayloadSize(32);

            uint8_t addr[] = RADIO_ADDRESS;
            radio.openWritingPipe(addr);
            radio.openReadingPipe(1, addr);
            radio.setAutoAck(false);

            radio.printDetails(); // DEBUG
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
            boost::this_thread::sleep(boost::posix_time::microseconds(RADIO_ON_AIR_US));
            
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
                    
                    // DEBUG
                    //for (unsigned int i = 0; i < sizeof(cowpacket); ++i) {
                    //    std::cout << (int)(read_buf[i]) << " ";
                    //}
                    //std::cout << std::endl;

                    //if (cowpacket_check_checksum(cp)) {
                        unsigned char payload[PAYLOAD_MAX_LENGTH+1];
                        payload[PAYLOAD_MAX_LENGTH] = 0;
                        memcpy(payload, cp->payload, PAYLOAD_MAX_LENGTH);

                        // transform payload to base64 to preserve null bytes etc.
                        std::string payload_base64 = base64_encode(payload, PAYLOAD_MAX_LENGTH);
                        std::stringstream ss;
                        ss << "{ " <<
                            "\"version\": \""   << (int)cp->version << "\", " <<
                            "\"seq_no\": \""    << (int)cp->seq_no << "\", " <<
                            "\"ttl\": \""       << (int)cp->ttl << "\", " <<
                            "\"address\": \""   << (int)cowpacket_get_address(cp) << "\", " <<
                            "\"type\": \""      << (int)cowpacket_get_type(cp) << "\", " <<
                            "\"is_fragment\": \"" << (int)cowpacket_get_is_fragment(cp) << "\", " <<
                            "\"payload\": \""   << payload_base64 << "\" " <<
                            " }";
                        
                        pkt_callback(ss.str());
                    //}
                    //else {
                    //    std::cerr << "Got corrupt packet." << std::endl;
                    //}
                }

                boost::this_thread::sleep(boost::posix_time::microseconds(RADIO_ON_AIR_US/4));
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
        void (*pkt_callback)(std::string);
};


#endif  // NRF_SERVER_H
