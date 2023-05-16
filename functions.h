#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

void ADD (char *data, char *activity);
void CLEAR (char *data);
void CLOSE (char *current_data);
void COMMON_M (char *month);
void COMMON_D (char *day_start, char *day_end);
void COUNT (char *data);
void DEL (char *data, int n);
void FULL_CLEAR ();
void MONTH (char *month);
void MOVE_ONLY (char *previous_data, char *next_data, int n);
void SHOW (char *data);