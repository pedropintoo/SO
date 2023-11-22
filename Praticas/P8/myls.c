#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>

int main(int argc, char* argv[]) {

    printf("====================================================\n");
    int ret = fork();
    
    if (ret == 0) execl("/bin/ls","ls","-la",NULL);

    wait(NULL);
    printf("====================================================\n");

    return EXIT_SUCCESS;
}