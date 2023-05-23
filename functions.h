#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <math.h>

void ADD (char *data, char *activity); // done
void CLEAR (char *data); // done
void CLOSE (char *current_data); // done
void COMMON_M (char *month, char *data); // done
void COMMON_D (char *day_start, char *day_end, char *data); // done
void COUNT (char *data); // done
void DEL (char *data, int n); // done
void FULL_CLEAR (); // done
void MONTH (char *month, char *data); // done
void MOVE_ONLY (char *previous_data, char *next_data, int n); // done
void SHOW (char *data); // done
void MOVE(char *data, char *new_data); // done