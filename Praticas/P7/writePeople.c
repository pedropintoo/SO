#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <assert.h>
#define MAX_PEOPLE 100



typedef struct
{
    int age;
    double height;
    char name[64];
} Person;

void printPersonInfo(Person *p)
{
    printf("Person: %s, %d, %f\n", p->name, p->age, p->height);
}

int main (int argc, char *argv[])
{
    FILE *fp = NULL;
    int i;

    /* Validate number of arguments */
    if(argc != 2)
    {
        printf("USAGE: %s fileName\n", argv[0]);
        return EXIT_FAILURE;
    }

    /* Open the file provided as argument */
    errno = 0;
    fp = fopen(argv[1], "wb");
    if(fp == NULL)
    {
        perror ("Error opening file!");
        return EXIT_FAILURE;
    }

    int n_persons;
    printf("Number of persons: ");
    scanf("%d",&n_persons);
    assert(n_persons <= MAX_PEOPLE);

    Person p;
    /* Write n_persons itens on a file */
    for(i = 1 ; i <= n_persons ; i++)
    {
        printf("[%d]\n",i);
        printf("Name: ");
        scanf("%s",p.name);
        printf("Age: ");
        scanf("%d",&(p.age));
        printf("Height: ");
        scanf("%lf",&(p.height));

        fwrite(&p, sizeof(Person), 1, fp);
    }


    fclose(fp);

    return EXIT_SUCCESS;
}
