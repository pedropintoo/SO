//
// Created by pedro on 28-10-2023.
//
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int main(int args, char* argv[]) {

    int length = 0;
    for (int i = 1; i < args; i++) if isalpha(argv[i][0]) length += strlen(argv[i]);

    char* new_array = (char*)malloc(length+1); // size of char is 1 byte

    new_array[0] = '\0';

    for (int i = 1; i < args; i++) if isalpha(argv[i][0]) strcat(new_array, argv[i]);


    printf("%s\n",new_array);

    free(new_array);

    return EXIT_SUCCESS;
}