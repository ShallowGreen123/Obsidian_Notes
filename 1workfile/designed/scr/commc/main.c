//
// Created by Administrator on 2023/5/26.
//

#include <stdio.h>
#include <stdlib.h>
#include "commc.h"
#include "commc_port.h"

commc_obj_t commc_handel;

//
#define COMMC_TYPE_BT_UART    1
#define COMMC_TYPE_DEBUG_UART 2
#define COMMC_TYPE_USE_UART   3

#define COMMC_ROLE_MASTER     1
#define COMMC_ROLE_SLAVE      0

int main()
{
    commc_install(COMMC_TYPE_BT_UART, NULL, &commc_port_uart, COMMC_ROLE_MASTER, 0);
    commc_install(COMMC_TYPE_DEBUG_UART, NULL, &commc_port_uart, COMMC_ROLE_MASTER, 0);
    commc_install(COMMC_TYPE_USE_UART, NULL, &commc_port_uart, COMMC_ROLE_MASTER, 0);

    commc_uninstall(COMMC_TYPE_DEBUG_UART);
    printf("hello commc\n");
    printf("commc_pack size :%ld\n", sizeof(commc_handel));
    return 0;
}
