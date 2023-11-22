#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SUGESTÂO: utilize as páginas do manual para conhecer mais sobre as funções usadas:
  man opendir
  man readdir
*/

void listDir(char dirname[])
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
                    printf("d %s/%s\n",dirname,dent->d_name);
                    //printf("->\n");
                    strcat(dirname, "/");
                    strcat(dirname,dent->d_name);
                    listDir(dirname);
                    strcpy(dirname,aux_dirname); // return with the copy
                    //printf("->\n");
                    break;
                default:
                    printf("  %s/%s\n",dirname,dent->d_name);
            }
        }

        dent = readdir(dp);
    }
}

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        fprintf(stderr,"Usage: %s base_directory\n",argv[0]);
        return EXIT_FAILURE;
    }

    listDir(argv[1]);
    
    return EXIT_SUCCESS;
}

