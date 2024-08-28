#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{   
    //printf("ARG: %d\n",argc);
    printf("Filho: PID = %d, PPID = %d\n", getpid(), getppid());
    sleep(9);
    printf("Filho: PID = %d, PPID = %d\n", getpid(), getppid());
    
    return EXIT_FAILURE;
}
