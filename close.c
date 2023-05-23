#include "functions.h"

void CLOSE(char *current_data)
{
	// printf("DATA: %s\n", current_data);
	int day, month, year;
	int i = 0;
	current_data[2] = '.';
	current_data[5] = '.';
	char directory[20];
	char next_data[11];
	for(i = 0; i < 7; i++) {
		day = (current_data[1] - '0') + (current_data[0] - '0') * 10;
		month = (current_data[4] - '0') + (current_data[3] - '0') * 10;
		year = (current_data[9] - '0') + (current_data[8] - '0') * 10 + (current_data[7] - '0') * 100 + (current_data[6] - '0') * 1000;
		if (day == 28 && month == 2) {
			if (year % 4 == 0) {
				day ++; //an bisect
				goto next;
			} else {
				day = 1;
				month = 3;
				goto next;
			}
		}
		if (day == 29 && month == 2) {
			day = 1;
			month = 3;
			goto next;
		}
		if (day == 30 && (month == 4 || month == 6 || month == 9 || month == 11)) {
			day = 1;
			month ++;
			goto next;
		}
		if (day == 31 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10)) {
			day = 1;
			month ++;
			goto next;
		}
		if (day < 28) {
			day ++;
			goto next;
		}
		if (day == 29 && month != 2) {
			day ++;
			goto next;
		}
		if (day == 28 && month != 2) {
			day ++;
			goto next;
		}
		if (day == 30 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)) {
			day ++;
			goto next;
		}
		if (day == 31 && month == 12) {
			day = 1;
			month = 1;
			year ++;
			goto next;
		}
next:
		if (day < 10) {
			next_data[0] = '0';
			next_data[1] = day + '0';
		} else {
			next_data[0] = day / 10 + '0';
			next_data[1] = day % 10 + '0';
		}
		if (month < 10) {
			next_data[3] = '0';
			next_data[4] = month + '0';
		} else {
			next_data[3] = month / 10 + '0';
			next_data[4] = month % 10 + '0';
		}
		next_data[6] = year / 1000 + '0'; 
		next_data[7] = (year % 100) / 100 + '0';
		next_data[8] = (year / 10) % 10 + '0';
		next_data[9] = year % 10 + '0';
		next_data[10] = 0;
		// printf("NEXT : %s\n", next_data);
		SHOW(next_data);
		strcpy(current_data, next_data);
	}
}	