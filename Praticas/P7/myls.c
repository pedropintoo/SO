//
// Created by pedro on 09-11-2023.
//
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>


void listDir(char dirname[], int option)
{
    DIR *dp;
    struct dirent *dent;

    char aux_dirname[strlen(dirname)+1];
    strcpy(aux_dirname,dirname);

    dp = opendir(dirname);
    if(dp == NULL)
    {
        perror("Error opening directory");
        return;
    }
    dent = readdir(dp);
    while(dent!=NULL)
    {
        if(dent->d_name[0] != '.') /* do not list hidden dirs/files */
        {

            switch (dent->d_type) {
                case DT_DIR:
                    if(option == 0 || option == 2) printf("d %s/%s\n",dirname,dent->d_name);
                    //printf("->\n");
                    strcat(dirname, "/");
                    strcat(dirname,dent->d_name);
                    listDir(dirname, option);
                    strcpy(dirname,aux_dirname); // return with the copy
                    //printf("->\n");
                    break;
                default:
                    if (option == 3) {
                        if (strrchr(dent->d_name, '.') != NULL)
                            if(strcmp(strrchr(dent->d_name, '.'),".txt") == 0)
                                printf("  %s/%s\n",dirname,dent->d_name);

                    } else if(option == 0 || option == 1) printf("  %s/%s\n",dirname,dent->d_name);
            }

        }

        dent = readdir(dp);
    }
}

int main(int argc, char *argv[])
{
    int opt;
    int option = 0;

    int option_index = 0;
    struct option long_options[] = {
            {    "file", no_argument, 0,  0  },
            { "dir",       no_argument, 0,  0  },
            { "txt", no_argument, 0,  0  },
            {        0,                 0, 0,  0  }
    };

    /* The getopt() function parses the command-line arguments. Its arguments
      argc and argv are the argument count and array as passed to the main()
      function on program invocation. An element of argv that starts with
      '-' (and is not exactly "-" or "--") is an option element. The charac‐
      ters of this element (aside from the initial '-') are option charac‐
      ters.  If getopt() is called repeatedly, it returns successively each
      of the option characters from each of the option elements.

      For more information check the man page (man 3 getopt)
     */
    while ((opt = getopt_long(argc, argv, "fde",long_options, &option_index)) != -1)
    {
        switch (opt)
        {
            case 0:

                if (strcmp(long_options[option_index].name, "file") == 0) {
                    option = 1;
                } else if (strcmp(long_options[option_index].name, "dir") == 0) {
                    option = 2;
                } else if (strcmp(long_options[option_index].name, "txt") == 0) {
                    option = 3;
                } else {
                    fprintf(stderr,"Usage: %s [-f|-d|-t] base_directory\n",argv[0]);
                    exit(EXIT_FAILURE);
                }
                break;
            case 'f':
                option = 1;
                break;
            case 'd':
                option = 2;
                break;
            case 't':
                option = 3;
                break;
            default: /* '?' */
                fprintf(stderr,"Usage: %s [-f|-d|-t] base_directory\n",argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    // Ensure only one option is provided
    if(argc < 1)
    {
        fprintf(stderr,"Usage: %s [-f|-d|-t] base_directory\n",argv[0]);
        return EXIT_FAILURE;
    }

    printf("option: %s\n",option == 0 ? "NA" : option == 1 ? "-f" : option == 2 ? "-d" : "-t" );
    int idx = 1;
    if (option != 0) idx++;


    int n_dir = argc - idx;
    if (n_dir == 0) {
        printf("No directory!\n");
        exit(EXIT_FAILURE);
    }

    // No dir -> no listDir()
    for (int i = 0; i < n_dir; i++)
        listDir(argv[idx+i], option);


    return EXIT_SUCCESS;
}
