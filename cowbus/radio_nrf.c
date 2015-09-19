/**
 * @author  Michael Zapf <michael.zapf@fau.de>
 * @date    2015-01-20
 * @file
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "board.h"      // cowbus-one
#include "cpu.h"        // stmf0 ?
#include "periph/gpio.h"
#include "thread.h"
#include "nrf24l01p.h"
#include "nrf24l01p_settings.h"
#include "xtimer.h"

#include "radio_nrf.h"
#include "radio_config.h"

#include "cowmac.h"

/// @brief instance of RIOTs nrf24l01p driver
nrf24l01p_t nrf24l01p_0;



void radio_nrf_init(void) {
    // initialize radio module
    //                                              ce       cs    irq
    int ret = nrf24l01p_init(&nrf24l01p_0, SPI_0,
            GPIO_NRF_CE,          // CE
            GPIO_NRF_CSN,         // CSN
            GPIO_NRF_IRQ);        // IRQ
    
    if (ret < 0) {
        printf("Transceiver initialization failed: %i\n", ret);
    }


    nrf24l01p_set_channel(&nrf24l01p_0, RADIO_RF_CHANNEL);
    char addr[] = RADIO_ADDRESS;
    nrf24l01p_set_tx_address(&nrf24l01p_0, addr, INITIAL_ADDRESS_WIDTH);
    nrf24l01p_set_rx_address(&nrf24l01p_0, NRF24L01P_PIPE0, addr, INITIAL_ADDRESS_WIDTH);

#if RADIO_DATARATE == DR_250KB
    nrf24l01p_set_datarate(&nrf24l01p_0, NRF24L01P_DR_250KBS);
#elif RADIO_DATARATE == DR_1MBS
    nrf24l01p_set_datarate(&nrf24l01p_0, NRF24L01P_DR_1MBS);
#else
    nrf24l01p_set_datarate(&nrf24l01p_0, NRF24L01P_DR_2MBS);
#endif

    thread_create(
        cowmac_receiver_stack, sizeof(cowmac_receiver_stack), THREAD_PRIORITY_MAIN - 1, 0,
        cowmac_receiver, 0, "cowmac_receiver");

    nrf24l01p_disable_all_auto_ack(&nrf24l01p_0); // disable all auto ack
    
    xtimer_usleep(DELAY_DATA_ON_AIR); // DEBUG: wait for sure...
    nrf24l01p_set_rxmode(&nrf24l01p_0);
    xtimer_usleep(DELAY_DATA_ON_AIR); // DEBUG: wait for sure...

    printf("Transceiver initialization finished.\n");
}

void radio_nrf_send_data(char* payload, unsigned short payload_length) {
    // power on the device
    int r = nrf24l01p_on(&nrf24l01p_0);
    
    xtimer_usleep(DELAY_DATA_ON_AIR/4); // DEBUG: wait for sure...
    
    // setup device as transmitter
    r = nrf24l01p_set_txmode(&nrf24l01p_0);
    
    // load data to transmit into device
    r = nrf24l01p_preload(&nrf24l01p_0, payload, payload_length);
    
    // trigger transmitting
    nrf24l01p_transmit(&nrf24l01p_0);

    /* wait while data is pysically transmitted  */
    xtimer_usleep(2*DELAY_DATA_ON_AIR);     // DEBUG: wair double for sure...

    r = nrf24l01p_get_status(&nrf24l01p_0);
    if (r & TX_DS) {
        // all good
        printf("Sent Packet\n");
    }
    else {
        //TODO error handling
    }

    // setup device as receiver
    nrf24l01p_set_rxmode(&nrf24l01p_0);
}

int8_t radio_get_rssi(void) {
    int8_t rssi;
    nrf24l01p_read_reg(&nrf24l01p_0, REG_RPD, (char*)&rssi);
    return rssi;
}


