#include "functions.h"

void MOVE_ONLY(char *previous_data, char *next_data, int n)
{
	previous_data[2] = '.';
	previous_data[5] = '.';
	next_data[2] = '.';
	next_data[5] = '.';
	char previous_directory[20], next_directory[20];
	strcpy (previous_directory, "directory/");
	strcat (previous_directory, previous_data);
	strcpy (next_directory, "directory/");
	strcat (next_directory, next_data);
	FILE *in = fopen(previous_directory, "rt");
	if (in == NULL) {
		printf("In data %s\nNIMIC PROGRAMAT\n", previous_data);
		return;
	}
	int i = 0, j = 0, exista = 0;
	char *activity = malloc(300 * sizeof(char));
	char **V = NULL;
	V = malloc(100 * sizeof(char *));
	for (i = 0; i < 100; i++) {
		V[i] = malloc(300 * sizeof(char));
	} 
	i = 0;
	while (fgets(activity, 300, in)) {
		strcpy(V[i], "A");
		strcat(V[i], activity);
		strcat(V[i], "A");
		if (i == n - 1) {
			ADD(next_data, V[i]);
			exista = 1;
		}
		i ++;
	}
	if (exista == 0) {
		printf("Nu exista activitatea %d in ziua %s", n, previous_data);
		for(i = 0; i < 100; i++) {
			free(V[i]);
		}
		free(V);
		free(activity);
		fclose(in);
		return;
	}
	CLEAR(previous_data);
	for(j = 0; j < i; j++) {
		if (j != n - 1)  {
			ADD(previous_data, V[j]);
		}
	}
	for(i = 0; i < 100; i++) {
		free(V[i]);
	}
	free(V);
	free(activity);
	fclose(in);
}