#include <stdio.h>

int strlen(char *s);

int main()
{
	int c, i=0;
	char s[20];
	char *sp;
	sp = &s[0];

	printf("Please enter a string: ");
	while ((c = getchar()) && c != '\n') {
		s[i] = c;
		i++;
	}
	s[i] = '\0';
	printf("String length: %d\n", strlen(sp));
}

int strlen(char *s)
{
	int i=0, n;

	/*
	for (;;) {
		if (*(s+i) != '\0') {
			i++;
		} else {
			return i;
		}
	}
	*/

	// textbook way -- did it myself with the first one
	for (n = 0; *s != '\0'; s++)
		n++;
	return n;
}
