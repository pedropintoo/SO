//
// Created by pedro on 28-10-2023.
//
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int args, char* argv[]) {

    int length = 0;
    for (int i = 1; i < args; i++) length += strlen(argv[i]);


    char* new_array = (char*)malloc(length+1); // size of char is 1 byte

    new_array[0] = '\0';

    for (int i = 1; i < args; i++) strcat(new_array, argv[i]);


    printf("%s",new_array);

    free(new_array);

    return EXIT_SUCCESS;
}