#ifndef _COMMC_INCLUDE_
#define _COMMC_INCLUDE_

#ifdef COMMC_MODULE_C
#define EXT_COMMC
#else
#define EXT_COMMC extern
#endif

/* include */
#include <stdint.h>
#include "commc_port.h"

/* config */
#define RX_RING_BUF_SIZE    1024
#define TX_RING_BUF_SIZE    1024

/* define */
#define COMMC_FAILT_EXIT -1
#define COMMC_OBJ_MAX_NUM   3
#define COMMC_REPLY_MAX_NUM 3

// #define COMMC_TYPE_BT_UART    1
// #define COMMC_TYPE_DEBUG_UART 2
// #define COMMC_TYPE_USE_UART   3

// #define COMMC_ROLE_MASTER     1
// #define COMMC_ROLE_SLAVE      0

/* data */
// head
struct commc_ver {
    uint16_t len : 10;
    uint16_t ver : 6;
} __attribute__((packed));

struct commc_head_head {
    uint8_t          sof;
    struct commc_ver ver;
    uint8_t          crc8;
} __attribute__((packed));

typedef struct commc_head_v1_t {
    uint8_t          sof;
    struct commc_ver ver;
    uint8_t          crc8;
    uint8_t          sender;
    uint8_t          recver;
    uint16_t         seq_num;
    uint8_t          cmd_type;
    uint8_t          cmd_set;
    uint8_t          cmd_id;
} __attribute__((packed)) commc_head_v1_t;

// reply
struct commc_obj_t;
typedef void (*commc_reply_cb)(struct commc_obj_t *entry);
typedef void (*callback_fn)(void *);
typedef void (*commc_slave_reply_fn)(struct commc_head_v1_t *rx_h, struct commc_obj_t *entry);

typedef struct commc_reply_info {
    commc_reply_cb arr[COMMC_REPLY_MAX_NUM];
    uint8_t        cnt;
} __attribute__((packed)) commc_reply_info_t;

// commc obj
typedef struct commc_obj_t {
    uint8_t            rx_buf[RX_RING_BUF_SIZE];
    uint16_t           rx_head;
    uint16_t           rx_tail;
    uint16_t           rx_len;
    uint8_t            tx_buf[TX_RING_BUF_SIZE];
    uint16_t           tx_head;
    uint16_t           tx_tail;
    uint16_t           tx_len;
    uint16_t           role : 6;
    uint16_t           type : 10;
    void              *uart;
    uint8_t            recv_data;
    uint32_t           last_tick;
    uint32_t           last_commt_time;
    commc_port_t      *port;
    commc_reply_info_t reply;
} __attribute__((packed)) commc_obj_t;

typedef struct commc_obj_list_t {
    uint8_t      cnt;
    commc_obj_t *arr[COMMC_OBJ_MAX_NUM];
} commc_obj_list_t;

/* extern */
EXT_COMMC void         commc_init(void);
EXT_COMMC void         commc_install(uint8_t uart_id,
                                     void   *uart,
                                     void   *port,
                                     uint8_t role,
                                     uint8_t slave_addr);
EXT_COMMC int commc_register_reply_cb(uint8_t uart_id, commc_reply_cb cb);
EXT_COMMC int commc_get_obj(uint8_t uart_id);
EXT_COMMC void         commc_uninstall(uint8_t uart_id);

#endif
