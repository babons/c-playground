#include <stdio.h>

void strncpy(char *s, char *t, int n);

int main()
{
	char *s = "hello";
	char t[100];
	int n;

	strncpy(s, t, 4);

	printf("%s\n", t);
	return 0;
}

void strncpy(char *s, char *t, int n)
{
	int i = 1;

	while ((*t++ = *s++) && i < n)
		i++;
	//t++ = '\0';
}
