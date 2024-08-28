#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

#define NTIMES 50

static int counter = 0;
static void Interrupt (int);

int main(int argc, char *argv[])
{
    struct sigaction sigact;
    unsigned int i;

    /* altera a rotina de atendimento ao ^C */
    sigact.sa_handler = Interrupt;
    sigemptyset (&sigact.sa_mask);
    sigact.sa_flags = 0;
    if (sigaction(SIGINT, &sigact, NULL) < 0) { 
        perror("Rotina de atendimento não instalada\n");
        return EXIT_FAILURE;
    }

    /* contador */
    printf("PID = %u\n", getpid());
    i = 0;
    while (i <= NTIMES) { 
       printf("\r%08u ", i++);
       fflush(stdout);
       sleep(1);
    }
    printf("\n");
 
    return EXIT_SUCCESS;
}


static void Interrupt (int signum)
{
    if (signum == SIGINT) {
        if(++counter == 4) {
            struct sigaction defaultSigAct;
            defaultSigAct.sa_handler = SIG_DFL;
            defaultSigAct.sa_flags = 0;
            sigaction(SIGINT, &defaultSigAct, NULL);
        }
        printf("\nCalma, ainda não cheguei a %d! |\033[32m%d\033[0m/\033[31m4\033[0m|\n", NTIMES,counter);
    }
    else {  
        printf("Foi recebido um sinal diferente de SIGINT!\n");
        exit(EXIT_FAILURE);
    }
}
