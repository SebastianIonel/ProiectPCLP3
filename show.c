#include "functions.h"

void SHOW(char *data)
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
		printf("%s\n", activity);
	}
	free(activity);
	fclose(in);
}