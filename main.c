#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("syntax error\n");
        printf("syntax: ./schedule dd/mm/yyyy\n");
        return 1;
    } 
    if (argv[1][2] != '/' || argv[1][5] != '/') {
        printf("syntax error\n");
        printf("syntax: ./schedule dd/mm/yyyy\n");
        return 1;
    }

    // Afisare obiective AZI
    // sterge date mai vechi
    // pentru PATH => creare directory
    char *command = NULL;
    command = malloc(300 * sizeof(char));
    if (command == NULL) {
        return 1;
    }
    
    while (1) {
        fgets(command, 300, stdin);
        // printf("%ld\n", strlen(command));
        // fputs(command, stdout);
        if (command[0] == 'E') {
            break;
        }

    }
    
    
    
    
    
    
    // FILE *f = fopen("text", "wt");
    // if (f == NULL) {
    //     printf("NU EXISTA\n");
    // }
    
    // mkdir("directory", 0700);


    return 0;
}