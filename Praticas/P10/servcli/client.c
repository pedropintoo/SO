/**
 * Nome    : client.c
 * Função  : cliente do servidor conversor para maisculas
 * Autores : Artur Pereira e José Luís Oliveira
 * Email   : {artur, jlo}@ua.pt
 */

#include "comm.h"

#include <unistd.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>

int main(void)
{
   MESSAGE msg;
   int nProc = 0;

   /* abre o canal de comunicacao */
   cliOpenComm();

   /* uso do serviço */
   while (1) { 
        /* pede expressao ao utilizador e constroi mensagem */
        printf("Mensagem a enviar: ");
        fgets(msg.data, MSG_MAX, stdin);
        msg.size = strlen(msg.data+1);

        if(fork() == 0) {
            nProc++;
            /* envia mensagem */
            cliSend(&msg);

            /* aguarda e recolhe resposta */
            cliReceive(&msg);
            /* imprime mensagem recebida */
            printf("Mensagem recebida: %s\n", msg.data);
            break;
        }

    } 

   /* espera pelos termo dos incrementadores e sai */
    for (int i = 0; i < nProc; i++) {
        wait(NULL);
    }

    nProc--;

   /* fecha o canal de comunicacao */
   cliCloseComm();

   return 0;
}
