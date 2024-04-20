#include "commc_port.h"

void uart_send_byte(void *private, uint8_t data)
{
}

uint8_t uart_recv_byte(void *private)
{
    return 0;
}

port_st_e uart_get_irq_st(void *private)
{
    return COMMC_PORT_IDLE;
}

void uart_tx_en(void *private)
{
}

void uart_rx_en(void *private)
{
}

void uart_tx_un(void *private)
{
}

void uart_rx_un(void *private)
{
}

void uart_send_first(void *private)
{
}

commc_port_t commc_port_uart = {
    .send       = uart_send_byte,
    .recv       = uart_recv_byte,
    .get_irq    = uart_get_irq_st,
    .rx_en      = uart_rx_en,
    .rx_un      = uart_rx_un,
    .tx_en      = uart_tx_en,
    .tx_un      = uart_tx_un,
    .send_first = uart_send_first,
};
