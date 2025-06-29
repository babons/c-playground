#include <stdio.h>

/*
my implementation of strend(s, t)
*/

int strend(char *s, char *t);

int main()
{
	char *s = "warlock";
	char *t = "lock";

	printf("%d\n", strend(s, t));
	return 0;
}

int strend(char *s, char *t)
{
	int ls, lt; //length of each
	char ct;
	ls = lt = 0;
	while (*s) {
		s++;
		ls++;
	}
	while (*t) {
		t++;
		lt++;
	}
	ct = *(t-1); // in check, if there is a match t points to last char

	if (lt > ls) return 0; // gpt error check

	while (*s-- == *t--)
		printf("good, s: %c, t: %c\n", *s, *t);
	if (*t == ct) return 1;
	return 2;
}
