#include "functions.h"

void DEL(char *data, int n)
{
	data[2] = '.';
	data[5] = '.';
	char directory[22];
	strcpy (directory, "directory/");
	strcat (directory, data);
	FILE *in = fopen(directory, "rt");
	if (in == NULL) {
		printf("In data %s\nNIMIC PROGRAMAT\n", data);
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
		if (i != n - 1) {
			strcpy(V[i], "A");
			strcat(V[i], activity);
			strcat(V[i], "A");
		}
		if (i == n - 1) {
			exista = 1;
		}
		i ++;
	}
	if (exista == 0) {
		printf("Nu exista activitatea %d in ziua %s", n, data);
		for(i = 0; i < 100; i++) {
			free(V[i]);
		}
		free(V);
		free(activity);
		fclose(in);
		return;
	}
	CLEAR(data);
	for(j = 0; j < i; j++) {
		if (j != n - 1)  {
			ADD(data, V[j]);
		}
	}
	for(i = 0; i < 100; i++) {
		free(V[i]);
	}
	free(V);
	free(activity);
	fclose(in);
}