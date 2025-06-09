#include <stdio.h>

/*
Program which displays a histogram of the length of words in its input.
*/

int main() {
	int c, i, j, wl;
	int lc[10];
	wl = 0;

	for (i = 0; i < 10; ++i) {
		lc[i] = 0;
	}

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n') {
			++lc[wl];
			wl = 0;
		} else {
			++wl;
		}
	}

	for (i = 0; i < 10; ++i) {
		printf("%d: ", i);
		for (j = 0; j < lc[i]; ++j) {
			printf(" |");
		}
		printf("\n");
	}
}
