#include <stdio.h>

/*
Simple program which counts tabs, blanks, and newlines
*/

int main()
{
	int c;
	int b = 0;
	int t = 0;
	int nl = 0;
	while ((c = getchar()) != EOF) {
	    printf("Char code: %d\n", c); // Add this line!
	    if (c == ' ')
	        ++b;
	    if (c == '\t')
	        ++t;
	    if (c == '\n')
	        ++nl;
}
	printf("There are %d blanks, %d tabs, and %d newlines.\n", b, t, nl);

	return 0;
}
