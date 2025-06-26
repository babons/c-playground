#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;
int getch(void);
void ungetch(int);
int getint(int *pn);

/*
getint: gets next integer from input and stores ino *pn
*/

int main()
{
	int n;
	for (;;) {
		printf("Enter input: \n");
		getint(&n);
		printf("Input: %d\n", n);
	return 0;
}

int getint(int *pn)
{
	int c, sign, temp;

	while (isspace(c = getch()))
		;

	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c);
		return 0;
	}

	sign = (c == '-') ? -1 : 1;

	/* ex. 5-1 - originally + or - not followed by dig was zero,
	fix to push such a char back on the input */
	if (c == '+' || c == '-') {
		temp = getch();
		if (!isdigit(temp)) {
			ungetch(temp);
			ungetch(c);
			return 0;
		} else {
			ungetch(temp);
			c = getch();
		}
	}
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if (c != EOF)
		ungetch(c);
	return c;
}

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("error: buffer full\n");
	else
		buf[bufp++] = c;
}
