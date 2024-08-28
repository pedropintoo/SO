//
// Created by pedro on 28-10-2023.
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int main(int args, char* argv[])
{
    // Seed the random number generator with the current time
    srand(time(NULL));

    if (args != 3) return EXIT_FAILURE;

    int n1 = (int)strtod(argv[1], NULL);
    int n2 = (int)strtod(argv[2], NULL);

    if (n1 >= n2) return EXIT_FAILURE;

    printf("Limit: [%d, %d]\n",n1,n2);

    int secret = rand()%(n2-n1 + 1) + n1;
    //printf("Secret: %d\n",secret);

    int guess;
    int n_wrong = 0;
    do {

        printf("Guess: ");
        scanf("%d",&guess);

        if (guess == secret) printf("Congratulations, it's correct! ( %d wrongs )\n", n_wrong);
        else if (guess < secret) printf("More higher...\n");
        else printf("More lower...\n");

        n_wrong++;

    } while (guess != secret);

    return EXIT_SUCCESS;
}