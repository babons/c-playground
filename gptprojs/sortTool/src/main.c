#include <stdio.h>
#include "io.h"

#define MAXLINES 5000

char *lineptr[MAXLINES];

int main() {
	int nlines = 0;
	int opt;

	for (;;) {
		printf("Please select an option listed below: \n");
		printf("1 - Input Lines\n");
		printf("2 - Read Lines\n");
		printf("3 - Sort Lines\n");
		printf("4 - Exit\n");
		scanf("%i", &opt);
		while (getchar() != '\n' && getchar() != EOF);

		if (opt == 1) {
			nlines = readlines(lineptr, MAXLINES);
			if (nlines < 0) {
				printf("error: input too big");
				return 1;
			}
		} else if (opt == 2) {
			printf("\nYou entered:\n");
			writelines(lineptr, nlines);
		} else if (opt == 3) {
			printf("WIP");
		} else if (opt == 4) {
			printf("Bye!!!\n");
			return 0;
		} else {
			printf("wat\n");
		}
	}

	return 0;
}
