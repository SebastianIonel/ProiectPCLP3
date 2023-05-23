#include "functions.h"

void COUNT(char *data)
{
	data[2] = '.';
	data[5] = '.';
	char directory[20];
	strcpy (directory, "directory/");
	strcat (directory, data);
	FILE *in = fopen(directory, "rt");
	if (in == NULL) {
		printf("%d activitati\n", 0);
		return;
	}
	char *activity = malloc(300 * sizeof(char));
	int nr = 0;
	while (fgets(activity, 300, in)) {
		nr++;
	}
	printf("%d activitati\n", nr);
	free(activity);
	fclose(in);
}