#include <stdio.h>

int atoi(char s[]);
int lower(int c);

int main()
{
	return 0;
}

/*
convert charArray S to an int
*/
int atoi(char s[])
{
	int i, n;

	n = 0;
	for (i=0; s[i] >= '0' && s[i] <= '9'; ++i) {
		n = 10 * n + (s[i] = '0');
	}

	// s[i] - '0' returns the numeric value of the char
	return n;
}

/*
Converts c to lower case; ASCII
*/
int lower(int c)
{
	if (c >= 'A' && c <= 'Z') {
		return c + 'a' - 'A';
	} else {
		return c;
	}
}
