#include "functions.h"

typedef struct str {
    char *activity;
    int nr;
    int days[31];
}VectDays;


void COMMON_D (char *day_start, char *day_end, char *data)
{
    int day = 0, i = 0, day_s, day_e;
    FILE *f = NULL;
    char now_data[12], next_data[2], full_data[50];
    char month[10];
    VectDays *all;
    all = malloc(300 * sizeof(VectDays));
    if (all == NULL) {
        return;
    }
    for (day = 0; day < 300; day ++) {
        all[day].nr = 0;
        all[day].activity = NULL;
        for (i = 0; i < 32; i ++) {
            all[day].days[i] = 0;
        }
    }
    day_s = (day_start[1] - '0') + (day_start[0] - '0') * 10;
    day_e = (day_end[1] - '0') + (day_end[0] - '0') * 10;
    // formare string pentru luna corespunzatoare
    strcpy(month, data + 3);
    month[2] = 0;
    strcpy(now_data, ".");
    strcat(now_data, month);
    strcat(now_data, ".");
    strcpy(data, data + 6);
    strcat(now_data, data);
    // printf("%s\n", now_data);
    for (day = day_s; day <= day_e; day ++) {
        // printf("%d ", day);
        if (day < 10) {
			next_data[0] = '0';
			next_data[1] = day + '0';
		} else {
			next_data[0] = day / 10 + '0';
			next_data[1] = day % 10 + '0';
		}
        next_data[2] = 0;
        strcpy(full_data, "directory/");
        strcat(full_data, next_data);
        strcat(full_data, now_data);
        // printf("%s\n", full_data);
        f = fopen(full_data, "rt");
        if (f != NULL) {
            char *activity = malloc(300 * sizeof(char));
	        while (fgets(activity, 300, f)) {
                for (i = 0; i < 300; i ++) {
                    if (all[i].activity == NULL) {
                        all[i].activity = malloc(300 * sizeof(char));
                        if (all[i].activity == NULL) {
                            return;
                        }
                        strcpy(all[i].activity, activity);
                        all[i].nr ++;
                        all[i].days[day] = 1;
                        break;
                        // printf("%s %d\n", all[i].activity, all[i].nr);
                    } else {
                        if (strcmp(all[i].activity, activity) == 0) {
                            all[i].nr ++;
                            all[i].days[day] = 1;
                            break;
                        }
                    }
                }
	        }
            free(activity);
            fclose(f);
        }
    }
    for (i = 0; i < 300; i ++) {
        if (all[i].nr > 1) {
            printf("%s", all[i].activity);
            for (int j = 0; j < 32; j ++) {
                if (all[i].days[j] == 1) {
                    printf("%d ", j);
                }
            }
            printf("\n");
        }
        if (all[i].nr != 0) {
            // printf("%s\n", all[i].activity);
            free(all[i].activity);
        }       
    }
    free(all);
}