#include <stdio.h>
#define MAXLINE 1000

/*
This is a program which will read a set of text lines and print the longest.
*/

int acquireline(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
	int len; /* current line length */
	int max; /* longest length atm */
	char line[MAXLINE]; /* current input */
	char longest[MAXLINE]; /* where longest line atm will be safe */

	max = 0;
	while ((len = acquireline(line, MAXLINE)) > 0)
	{
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	}

	if (max > 0)
	{
		printf("%s", longest);
	}
	return 0;
}

/* function which reads a line into var s, returns its length */
int acquireline(char s[], int lim)
{
	int c, i;
	for (i = 0; i < lim-1 && (c=getchar()) != EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

/* function which copies the current line into the array for the longest line */
void copy(char to[], char from[])
{
	int i = 0;
	while ((to[i] = from[i]) != '\0')
	{
		++i;
	}
}
