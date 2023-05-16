#include "functions.h"

void ADD(char *data, char *activity)
{
	data[2] = '.';
	data[5] = '.';
	char directory[20];
	strcpy (directory, "directory/");
	strcat (directory, data);
	strcpy (activity, activity + 1);
	activity[strlen(activity) - 1] = 0; 
	strcat (activity, "\n");
	FILE *in = fopen(directory, "rt");
	if (in == NULL) {
		FILE *out = fopen(directory, "wt");
		if (out == NULL) {
			printf("Nu s-a putut deschide fisierul %s", directory);
			return;
		}
		fputs(activity, out);	
	} else {
		fclose(in);
		in = fopen(directory, "at");
		fputs(activity, in);
	}
}