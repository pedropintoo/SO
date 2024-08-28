/**
 * \brief C2
 * \author Pedro Pinto <pmap@ua.pt>
 */

#include "comm.h"

#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
    MESSAGE msg;

    /* opening the communication channel */
    cliOpenComm();

    /* use the service */
    while(1) {
        
        /* asking user for a message */
        printf("\n Send: ");
        fgets(msg.data, MSG_MAX, stdin);
        msg.size = strlen(msg.data)+1;

        /* sending converted message */
        cliSend(&msg);

        printf("\n\e[33mWainting for a message...\e[0m\n");

        /* getting first message from queue, blocking if necessary */ 
        cliReceive(&msg);

        printf("\n Receibed: %s",msg.data);
    }
    return 0;
}
