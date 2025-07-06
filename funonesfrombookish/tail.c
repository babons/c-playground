#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
my tail
*/

#define BUFFERSIZE 4096
#define MEMBLOCK 128
#define MAXLINES 64
#define DEFAULT 10

char buffer[BUFFERSIZE];
char *allocp = buffer;

char *alloc(int n)
{
	char *r = allocp;
	if ((allocp + n) > (buffer + BUFFERSIZE)) {
		printf("error: buffer full");
		return NULL;
	} else {
		allocp += n;
		return r;
	}
}

char *my_getline(int n)
{
	int c, i = 0;
	char *r = alloc(n);
	if (r == NULL ) {
		return NULL;
	}

	while (--n > 1 && (c = getchar()) != EOF && c != '\n') {
		r[i++] = c;
	}

	if (c == EOF && i == 0) {
		return NULL;
	} else if (c == '\n') {
		r[i++] = c;
	}
	r[i] = '\0';
//	printf("%s\n", r);
	return r;

}

int main(int argc, char *argv[])
{
	int n = DEFAULT;
	int i = 0;
	int start;
	char *lines[MAXLINES];
	char *p;

	if (argc == 3 && strcmp(argv[1], "-n") == 0) {
		n = atoi(argv[2]); // converts number arg to an int
		if (n <= 0) {
			printf("tail: invalid number of lines '%s'\n", argv[2]);
			return 1;
		}
	} else if (argc != 1) {
		printf("usage: tail [-n number]\n");
		return 1;
	}

	while ((p = my_getline(MEMBLOCK)) != NULL) {
		lines[i++] = p;
//		printf("%s\n", p);
	}

	start = (i > n) ? i - n: 0;

	while (start < i) {
		printf("%s", lines[start++]);
	}
}
