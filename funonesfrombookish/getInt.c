#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;
int getch(void);
void ungetch(int);
int getint(int *pn);
float getfloat(float *fp);

/*
getint: gets next integer from input and stores ino *pn
*/

int main()
{
	int n;
	float f;
	for (;;) {
		printf("Enter input: ");
		getint(&n);
		printf("Input: %d\n", n);
		printf("Enter float input: ");
		getfloat(&f);
		printf("Float Input: %f\n", f);
	}
	return 0;
}

float getfloat(float *fp)
{
	int c, p, sign, temp;
	while (isspace(c = getch()))
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
		ungetch(c);
		return 0;
	}

	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-') {
                temp = getch();
                if (!isdigit(temp) && temp != '.') {
                        ungetch(temp);
                        ungetch(c);
                        return 0;
                } else {
                        ungetch(temp);
                        c = getch();
                }
        }

	if (c == '.') {
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
	p = 1;
	for (*fp = 0; isdigit(c); c = getch()) {
		*fp = 10 * *fp + (c - '0');
		p *= 10;
	}
	if (c == '.') {
		double frac = 0.0;
		p = 1;
		while (isdigit(c = getch())) {
			frac = 10 * frac + (c - '0');
			p *= 10;
		}
		*fp += frac / p;
	}
	*fp *= sign;
	if (c != EOF)
		ungetch(c);
	return c;
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
