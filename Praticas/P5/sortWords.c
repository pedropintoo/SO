//
// Created by pedro on 30-10-2023.
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<assert.h>

int main(int args, char* argv[])
{
    assert(args > 0);

    int length = 0;
    for (int i = 1; i < args; i++) if isalpha(argv[i][0]) length++;

    char** new_array = (char**) malloc(length * sizeof(char*));

    int idx = 0;
    for (int i = 1; i < args; i++)
        if isalpha(argv[i][0]) {
            new_array[idx] = (char*)malloc(strlen(argv[i]+1)); // size of char is 1 byte
            new_array[idx][0] = '\0';
            strcat(new_array[idx++],argv[i]);
        }

    // Selection sort (not efficient)
    int sort_order = strtod(getenv("SORTORDER"),NULL);
    if (sort_order < 0) sort_order = -1; // Decrescente
    else sort_order = 1; // Crescente

    for (int i = 0; i < length-1; i++) {
        for (int j = i+1; j < length; j++) {
            // first string to lower case
            char* str1 = malloc(strlen(new_array[i])+1);
            str1[0] = '\0';
            for(int k = 0; k < strlen(new_array[i]); k++){
                str1[k] = tolower(new_array[i][k]);
            }
            // second string to lower case
            char* str2 = malloc(strlen(new_array[j])+1);
            str2[0] = '\0';
            for(int k = 0; k < strlen(new_array[j]); k++){
                str2[k] = tolower(new_array[j][k]);
            }

            if (sort_order * strcmp(str1,str2) > 0) {
                char* aux = malloc(strlen(new_array[i]));
                strcpy(aux, new_array[i]);
                strcpy(new_array[i], new_array[j]);
                strcpy(new_array[j], aux);
            }
        }
    }
    
    for (int i = 0; i < length; i++) printf("%s\n",new_array[i]);


    for (int i = 1; i < length; i++) free(new_array[i]);
    free(new_array);


    return EXIT_SUCCESS;
}
