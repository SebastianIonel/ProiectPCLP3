#include "functions.h"

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
    char *command = NULL, *p = NULL, *q = NULL, *location = NULL;
    char data[11];
    command = malloc(300 * sizeof(char));
    if (command == NULL) {
        return 1;
    }
    p = malloc (300 * sizeof(char));
    if (p == NULL) {
        return 1;
    }
    while (1) {
        fgets(command, 300, stdin);

        // printf("%ld\n", strlen(command));
        // fputs(command, stdout);
        if (strcmp(command, "EXIT\n") == 0) {
            break;
        }
        strcpy(p, command);
        q = strchr(p, ' ');
        if (q != NULL) {
            q[0] = 0;
        } else {
            q = strchr(p, '\n');
            q[0] = 0;
        }

        if (strcmp(p, "ADD") == 0) {
            strcpy(p, q + 1);
            q = strchr(p, ' ');
            q[0] = 0;
            strcpy(data, p);
            strcpy(p, q + 1);
            ADD(data, p);
            continue;
        }

        if (strcmp(p, "CLEAR") == 0) {
            // printf("Call CLEAR\n");
            strcpy(p, q + 1);
            q = strchr(p, '\n');
            q[0] = 0;
            strcpy(data, p);
            CLEAR(data);
            continue;
        }

        if (strcmp(p, "CLOSE") == 0) {
            printf("Call CLOSE\n");
            continue;
        }

        if (strcmp(p, "COMMON") == 0) {
            printf("Call COMMON\n");
            // compara cuv 2
            continue;
        }

        if (strcmp(p, "COUNT") == 0) {
            printf("Call COUNT\n");
            continue;
        }

        if (strcmp(p, "DEL") == 0) {
            printf("Call DEL\n");
            continue;
        }

        if (strcmp(p, "FULL_CLEAR") == 0) {
            printf("Call FULL_CLEAR\n");
            continue;
        }

        if (strcmp(p, "MONTH") == 0) {
            printf("Call MONTH\n");
            continue;
        }

        if (strcmp(p, "MOVE_ONLY") == 0) {
            printf("Call MOVE_ONLY\n");
            continue;
        }

        if (strcmp(p, "SHOW") == 0) {
            printf("Call SHOW\n");
            continue;
        }

        if (strcmp(p, "PATH") == 0) {
            // printf("PATHHHH\n");
            location = malloc(300 * sizeof(char));
            if (location == NULL) {
                return 1;
            }
            strcpy(location, q+1);
            location[strlen(location) - 1] = 0;
            strcat(location, "directory/");
            // printf("%s", location);
            mkdir(location, 0700);
            continue;
        }

    }
    
    
    
    // FILE *f = fopen("text", "wt");
    // if (f == NULL) {
    //     printf("NU EXISTA\n");
    // }
    
    // mkdir("directory", 0700);


    return 0;
}