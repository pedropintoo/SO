/**
 * \brief C1
 * \details This module open comunication channal and comunicate with C2
 * \autores : Pedro Pinto
 */

#include "comm.h"

#include <ctype.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int main(void)
{
    /* Creating communication channel */
    servOpenComm();

    /* the service */
    MESSAGE msg;
    while(1) {

        printf("\n\e[33mWainting for a message...\e[0m\n");
        /* getting first message from queue, blocking if necessary */ 
        servReceive(&msg);

        printf("\n Receibed: %s\n",msg.data);

        /* asking user for a message */
        printf("\n Send: ");
        fgets(msg.data, MSG_MAX, stdin);
        msg.size = strlen(msg.data)+1;

        /* sending converted message */
        servSend(&msg);
    }
    return 0;
}

