#include <stdio.h>

/*
textbook example of strcpy
*/

void strcpy(char *s, char *t);

int main()
{
	char *t = "hello world!";
	char s[100];

	strcpy(s, t);

	printf("%s\n", s);
	return 0;
}

/* void strcpy(char *s, char *t)
{
	int i = 0;

	while ((*s = *t) != '\0') {
		s++;
		t++;
	}
}
*/

void strcpy(char *s, char *t)
{
	while ((*s++ = *t++) != '\0')
		;
}
