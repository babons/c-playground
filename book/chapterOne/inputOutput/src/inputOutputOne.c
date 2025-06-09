#include <stdio.h>

/*
Simple program which takes a character for input and prints it with a newline appended.
*/

int main()
{
	char c;
	char n = '\n';
	c = getchar();
	putchar(c);
	putchar(n);

	return 0;
}
