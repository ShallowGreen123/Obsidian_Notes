
#include <stdlib.h>
#include "commc.h"

commc_obj_list_t obj_list = {
    .cnt = 0,
};
//
uint32_t get_tick()
{
    return 0;
}

void commc_install(uint8_t uart_id,
                   void   *uart,
                   void   *port,
                   uint8_t role,
                   uint8_t slave_addr)
{
    commc_obj_t *obj = NULL;

    if (commc_get_obj(uart_id) != COMMC_FAILT_EXIT) {
        return;
    }

    obj = (commc_obj_t *)malloc(sizeof(commc_obj_t));

    obj->rx_head         = 0;
    obj->rx_tail         = 0;
    obj->rx_len          = 0;
    obj->tx_head         = 0;
    obj->tx_tail         = 0;
    obj->tx_len          = 0;
    obj->role            = role;
    obj->type            = uart_id;
    obj->uart            = uart;
    obj->last_tick       = get_tick();
    obj->last_commt_time = 0;
    obj->port            = port;

    obj_list.arr[obj_list.cnt++] = obj;
}

int commc_register_reply_cb(uint8_t uart_id, commc_reply_cb cb)
{
    int reply_cnt;
    int id;
    id = commc_get_obj(uart_id);
    if(id != COMMC_FAILT_EXIT)
    {
        reply_cnt = obj_list.arr[id]->reply.cnt;
        if(reply_cnt >= COMMC_REPLY_MAX_NUM){
            return COMMC_FAILT_EXIT;
        }
        obj_list.arr[id]->reply.arr[reply_cnt] = cb;
        obj_list.arr[id]->reply.cnt = reply_cnt +1;
    }
    return 1;
}

int commc_get_obj(uint8_t uart_id)
{
    int          i;
    commc_obj_t *obj;
    for (i = 0; i < obj_list.cnt; i++) {
        if (uart_id == obj_list.arr[i]->type) {
            obj = obj_list.arr[i];
            return i;
        }
    }
    return COMMC_FAILT_EXIT;
}

void commc_uninstall(uint8_t uart_id)
{
    int i;
    for (i = 0; i < obj_list.cnt; i++) {
        if (uart_id == obj_list.arr[i]->type) {
            free(obj_list.arr[i]);
            obj_list.arr[i] = NULL;
            break;
        }
    }
}
