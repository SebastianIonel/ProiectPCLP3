#include "functions.h"

void FULL_CLEAR ()
{
    char name[50];
    DIR *d;
    struct dirent *dir;
    d = opendir("directory/");
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            // printf("%s\n", dir->d_name);
            strcpy(name, "directory/");
            strcat(name, dir->d_name);
            remove(name);
        }
    closedir(d);
    }
}