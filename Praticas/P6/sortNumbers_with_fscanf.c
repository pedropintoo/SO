#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define SIZE_MAX 100

/* SUGESTÂO: utilize as páginas do manual para conhecer mais sobre as funções usadas:
 man qsort
*/

int compareInts(const void *px1, const void *px2)
{
    int x1 = *((int *)px1);
    int x2 = *((int *)px2);
    return(x1 < x2 ? -1 : x1 == x2 ? 0 : 1);
}

int main(int argc, char *argv[])
{

    /* Validate number of arguments */
    if( argc != 2 )
    {
        printf("USAGE: %s <fileName>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int i, numSize;
    int *numbers;
    FILE *fp = NULL;

    /* Memory allocation for all the numbers in the arguments */
    numbers = (int *) malloc(sizeof(int) * SIZE_MAX); // max 100 numbers

    /* Open the file provided as argument */
    errno = 0;

    fp = fopen(argv[1], "r");

    if( fp == NULL )
    {
        perror ("Error opening file!");
        return EXIT_FAILURE;
    }

    i = 0;
    /* Read all the lines of the file */
    // fgets lê no maximo sizeof(line) -> size - 1 (ele nao depois mete o '\0' )
    // e acaba no EOF - end of file ou para no fim da linha (guardando o '\n')
    printf("Unsorted numbers: \n");
    int number;
    while (fscanf(fp, "%d", &number) != EOF)
    {
        /* Storing the arguments in the "array" numbers */
        numbers[i++] = number;
        printf("%d\n",numbers[i-1]);
    }
    fclose(fp);


    numSize = i;
    /* void qsort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *)); 
         The qsort() function sorts an array with nmemb elements of size size.*/
    qsort(numbers, numSize, sizeof(int), compareInts);

    /* Printing the sorted numbers */
    printf("Sorted numbers: \n");
    for(i = 0 ; i < numSize ; i++)
    {
        printf("%d\n", numbers[i]);
    }

    return EXIT_SUCCESS;
}
