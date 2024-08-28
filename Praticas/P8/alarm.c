#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char** argv)
{   
    printf("PID: %d\n",getpid());
    int input, n_alarm = 1;
    while (1) {
        printf("Define um alarme: ");
        scanf("%d",&input);
        if (fork() == 0) {
            sleep(input);
            printf("Alarm [%d] end!",n_alarm);
            exit(1);
        }
        n_alarm++;
    }
    return 0;
}