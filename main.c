#include<stdio.h>
#include<stdlib.h>

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

    return 0;
}