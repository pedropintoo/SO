#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SUGESTÂO: utilize as páginas do manual para conhecer mais sobre as funções usadas:
 man system
 man date
*/

int main(int argc, char *argv[])
{
    FILE *pipe_date;
    FILE* fp = fopen("console.log","a");
    char text[1024];

    do
    {
        printf("Command: ");
        scanf("%1023[^\n]%*c", text);

        // Open a pipe to the command
        pipe_date = popen("date '+%Y-%m-%d %H:%M:%S'", "r");
        char date[20];
        fgets(date, sizeof(date), pipe_date);
        fprintf(fp,"[%s] -> %s\n",date,text);

        /* system(const char *command) executes a command specified in command
            by calling /bin/sh -c command, and returns after the command has been
            completed.
        */
        if(strcmp(text, "end")) {
           printf("\n * Command to be executed: %s\n", text);
           printf("---------------------------------\n");
           system(text);
           printf("---------------------------------\n");
        }
    } while(strcmp(text, "end"));

    printf("-----------The End---------------\n");

    pclose(pipe_date);
    fclose(fp);

    return EXIT_SUCCESS;
}
