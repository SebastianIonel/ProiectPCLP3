#include "functions.h"

void MOVE(char *data, char *new_data)
{
	data[2] = '.';
	data[5] = '.';
	char directory[20];
	strcpy (directory, "directory/");
	strcat (directory, data);
	FILE *in = fopen(directory, "rt");
	if (in == NULL) {
		printf("In data %s\nNIMIC PROGRAMAT\n", data);
		return;
	}
	char *activity = malloc(300 * sizeof(char));
	while (fgets(activity, 300, in)) {
		ADD(new_data, activity);
	}
	remove(directory);
	free(activity);
	fclose(in);
}