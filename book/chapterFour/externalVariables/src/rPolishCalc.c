#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

/*
Program featuring a reverse Polish calculator.
*/

#define MAXOP	100
#define NUMBER	'0'
#define MAXVAL	100
#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;
int sp = 0;
double val[MAXVAL];

int getch(void);
void ungetch(int);
int getop(char []);
void push(double);
double pop(void);

int main()
{
	int type, i;
	double op2;
	char p;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		switch (type) {
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("error: zero div\n");
			break;
		case '%':
			op2 = pop();
			if (op2 != 0.0)
				push((int) pop() % (int) op2);
			else
				printf("error: no zero\n");
			break;
		case '^':
			op2 = pop();
			push(pow(pop(), op2));
			break;
		case 's':
			push(sin(pop()));
			break;
		case 'c':
			push(cos(pop()));
			break;
		case 'L':
			printf("%f, %f\n", val[sp - 1], val[sp - 2]);
			break;
		case 'D':
			if (sp > 0)
				push(val[sp-1]);
			else
				printf("error: stack is empty - nothing to duplication\n");
			break;
		case 'C':
			for (i = 0; i < sp; i++) {
				val[i] = 0;
			}
			sp = 0;
			break;
		case 'S':
			if (sp >= 2) {
				p = val[sp-1];
				val[sp-1] = val[sp-2];
				val[sp-2] = p;
			} else {
				printf("error: less than two values; can't swap");
			}
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("error :unknown command %s\n", s);
			break;
		}
	}
	return 0;
}

void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

int getop(char s[])
{
	int i = 0, c, nch;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (c == '-') {
		nch = getch();
		if (isdigit(nch) || nch == '.') {
			s[i++] = c;
			s[i++] = nch;
			c = nch;
		} else {
			ungetch(nch);
			return c;
		}
	} else if (!isdigit(c) && c != '.') {
        	return c; // not a number
    	} else {
	        s[i++] = c;
    	}

	if (isdigit(c))
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')
		while (isdigit(s[++i] = c = getch()))
			;
	s[i - 1] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
