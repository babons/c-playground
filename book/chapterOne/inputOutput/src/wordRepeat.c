#include <stdio.h>

/*
This is a program which will repeat words which are input
*/

int main()
{
	int c = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			putchar('\n');
		} else {
			putchar(c);
		}
	}
	return 0;
}
