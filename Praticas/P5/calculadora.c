
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(int argc, char *argv[])
{

    if (argc != 4) {
        printf("ERROR: 2 args needed\n");
        return EXIT_FAILURE;
    }
    
    double n1 = strtod(argv[1], NULL);
    const char *operation = argv[2];
    double n2 = strtod(argv[3], NULL);
    double result = 1;

    if (strcmp(operation,"+") == 0) {
        result = n1 + n2;
        printf("%.2f\n",result);
    } else if (strcmp(operation,"-") == 0) {
        result = n1 - n2;
        printf("%.2f\n",result);
    } else if (strcmp(operation,"x") == 0) {
        result = n1 * n2;
        printf("%.2f\n",result);
    } else if (strcmp(operation,"/") == 0) {
        result = n1 / n2;
        printf("%.2f\n",result);
    } else if (strcmp(operation,"p") == 0) {
        result = 1;
        for (int i = 0; i < n2; i++) result = result * n1;
        printf("%.2f\n",result);
    } else {
        printf("ERROR: invalid operation\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;

}