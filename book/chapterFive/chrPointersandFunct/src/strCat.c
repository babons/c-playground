#include <stdio.h>

/*
Function strcat which appends one string to the end of another.
*/

void strcat(char *s, char *t);

int main() {
	char *s = "world";
	char t[100] = "hello ";

	strcat(s, t);

	printf("Result: %s\n", t);
	return 0;
}

void strcat(char *s, char*t)
{
	// my original
	//while ((*t++) != '\0')
	//	;
	// *t--; // to start at null term to overwrite it

	//gpt suggestion
	while (*t)
		t++;

	while ((*t++ = *s++) != '\0') {
		;
	}
}
