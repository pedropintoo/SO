#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

/* SUGESTÂO: utilize as páginas do manual para conhecer mais sobre as funções usadas:
 man fopen
 man fgets
*/

#define LINEMAXSIZE 80 /* or other suitable maximum line size */


int main(int argc, char *argv[])
{
    FILE *fp = NULL;

    /* Validate number of arguments */
    if( argc < 2 )
    {
        printf("USAGE: %s <fileName+>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    /* Open the file provided as argument */
    errno = 0;
    for (int i = 1; i < argc; i++) {
        fp = fopen(argv[i], "r");

        if( fp == NULL )
        {
            perror ("Error opening file!");
            return EXIT_FAILURE;
        }

        int l = 1;
        printf("%d->",l++);
        /* Read all the lines of the file */
        int c;
        for( ;; )
        {
            c = fgetc( fp );

            if( c == EOF ){
                printf("\n");
                break;
            }
            if( c == '\n' ){
                printf("\n%d->",l++);
                continue;
            }


            printf("%c",c); /* not needed to add '\n' to printf because fgets will read the '\n' that ends each line in the file */
        }

        fclose(fp);
    }

    return EXIT_SUCCESS;
}