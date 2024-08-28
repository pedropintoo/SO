#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{   
    // int execl (const char *Path, const char *Argument0, const char *Argument1, ... , NULL);
    printf("Pai (antes do fork): PID = %u, PPID = %u\n", getpid(), getppid());
    switch (fork())
    {
      case -1: /* fork falhou */
               perror("Erro no fork\n");
               return EXIT_FAILURE;
      case 0:  /* processo filho */
               if (execl("/bin/ls", "ls", "-l", NULL) < 0) { 
                   perror("erro no lancamento da aplicacao");
                   return EXIT_FAILURE;
               }
               printf("Porque é que eu não apareço?\n");
               break;
      default: /* processo pai */
               sleep(1);
               printf("Pai (depois do fork): PID = %u, PPID = %u\n", getpid(), getppid());
    }
    // wait(NULL); // O Processo pai iria esperar que o processo filho acabasse a execução para terminar a sua execução 
    return EXIT_SUCCESS;
}
