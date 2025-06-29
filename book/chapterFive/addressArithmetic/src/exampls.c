#include <stdio.h>

/*
New way of going through the book -- writing up examples of all concepts.
*/

int main()
{
	char a[5];
	char *cp;
	cp = &a[0];

	int i;

	// increment pointer
	for (i = 0; i < 5; i++) {
		a[i] = 65 + i;
		printf("%c\n", *cp++);
	}

	return 0;
}
