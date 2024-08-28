/**
 * Nome    : server.c
 * Função  : servidor conversor de string para maisculas
 * Autores : Artur Pereira e José Luís Oliveira
 * Email   : {artur, jlo}@ua.pt
 */

#include "comm.h"

#include <ctype.h>
#include <stdio.h>
#include <math.h>

#define BIG 50000000

void delay(long nite)
{
    int k;
    double b = 0.0;
    double c = 0.0;
    double PI = 3.141516;

    for (k = 0; k < nite; k++)
    { 
        b = cos (c + PI/4);
        c = sqrt (fabs (b));
    }
}

int main(void)
{
    MESSAGE msg;
    int i;
    int cnt = 0;

    /* abre o canal de comunicação */
    servOpenComm();

    /* atendimento */
    while (1) { 
        /* le primeira mensagem da fila */
        servReceive(&msg);
 
        /* converte mensagem para maisculas */
        for (i = 0; i < msg.size; i++) {
            msg.data[i] = toupper(msg.data[i]);
            delay(BIG); 
        }

        /* envia de volta a mensagem processada */
        printf("String %d ", ++cnt); fflush(stdout);
        servSend(&msg);
        printf("processado.\n");
    }
 
    /* fecha o canal de comunicacao */
    servCloseComm();

    return 0;
}

