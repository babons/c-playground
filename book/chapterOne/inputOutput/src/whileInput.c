#include <stdio.h>

/*
Simple program which reads characters and prints them until EOF.
*/

int main()
{
	int c;

	while ((c = getchar()) != EOF) {
		putchar(c);
	}
}
