#ifndef _COMMC_PORT_INCLUDE_
#define _COMMC_PORT_INCLUDE_

#ifdef COMMC_PORT_C
#define EXT_COMMC_PORT
#else
#define EXT_COMMC_PORT extern
#endif

/* include */
#include <stdint.h>

/* config */

/* define */

/* data */
typedef enum _port_st_e {
    COMMC_PORT_IDLE = 0,
    COMMC_PORT_TX,
    COMMC_PORT_RX,
} port_st_e;

typedef void (*commc_port_send)(void *private_data, uint8_t data);
typedef uint8_t (*commc_port_receive)(void *private_data);
typedef port_st_e (*commc_port_get_irq_status)(void *private_data);
typedef void (*commc_port_tx_en)(void *private_data);
typedef void (*commc_port_rx_en)(void *private_data);
typedef void (*commc_port_tx_un)(void *private_data);
typedef void (*commc_port_rx_un)(void *private_data);
typedef void (*commc_port_send_first_byte)(void *entry);

typedef struct _commc_port_t {
    commc_port_send            send;
    commc_port_receive         recv;
    commc_port_get_irq_status  get_irq;
    commc_port_tx_en           tx_en;
    commc_port_rx_en           rx_en;
    commc_port_tx_un           tx_un;
    commc_port_rx_un           rx_un;
    commc_port_send_first_byte send_first;
} commc_port_t;


/* extern */
EXT_COMMC_PORT commc_port_t commc_port_uart;
#endif