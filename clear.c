#include "functions.h"

void CLEAR(char *data)
{
	data[2] = '.';
	data[5] = '.';
	char directory[20];
	strcpy (directory, "directory/");
	strcat (directory, data);
	if (remove(directory) != 0) {
		printf("Nu exista evenimente in data %s\n", data);
	}
}