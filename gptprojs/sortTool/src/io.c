#include "io.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFSIZE 4096
#define MAXLEN 16

static char allocbuf[BUFSIZE];
static char *allocp = allocbuf;
char *alloc(int n);

int readlines(char *lineptr[], int maxlines) {
	int i = 0; // line counter
	char string[MAXLEN]; // temp array for string input -- overwritten by each my_getline
	while (i != maxlines && my_getline(string, MAXLEN) > 0) {
		char *buffp = alloc(strlen(string) + 1); // alloc room for each line
		strcpy(buffp, string); // copy contents of string into the buffer
		lineptr[i++] = buffp; // copy string in the allocated space into our pointer array
	}
	return i;
}

void writelines(char *lineptr[], int nlines)
{
	int i = 0;
	while (i < nlines) {
		printf("%d: %s\n", i, lineptr[i]);
		i++;
	}
}

int my_getline(char *s, int lim)
{
	int i = 0;
	int c;
	char temp[lim];
	while ((c = getchar()) && c != '\n' && i < lim) {
		temp[i++] = c;
	}
	if (i < lim) {
		strcpy(s, temp);
		return i;
	} else {
		printf("Line too large. Please try again");
		return -1;
	}

	return i;
}

char *alloc(int n) {
	if(allocbuf + BUFSIZE - allocp >= n) {
		char *r = allocp; // return pointer if there is enough space
		allocp += n;
		return r;
	} else {
		return NULL;
	}
}
