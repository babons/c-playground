#include <stdio.h>
#define MAXLENGTH 1000
/*
Small program which replaces tabs in the input with a proper number of spaces.
Six from within nano (yes, I use nano) but three in terminal output.
*/

char string[MAXLENGTH];
int space = 3;
int length;

void replacetab();

int main()
{
	int i, c;
	extern char string[];
	extern int length;

	length = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			replacetab();
		} else {
			string[length] = c;
			++length;
		}
	}
	printf("\n%s\n", string);
	return 0;
}

void replacetab()
{
	extern char string[];
	extern int space;
	extern int length;
	int end = length + space;
	while (length != end) {
		string[length] = ' ';
		++length;
	}
}
