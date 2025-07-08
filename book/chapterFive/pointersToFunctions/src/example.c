#include <stdio.h>
#include <string.h>

/*
another fun line sorter... -n switch to switch between numerical or lexicographical compare
*/

#define MAXLINES 5000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(void *lineptr[], int left, int right,
	int (*comp) (void *, void *));

/*
int return type
(*comp) "comp is a pointer to a function"
(void *, void *) parameter types for the function being pointed to

comp is a pointer to a function which takes two void * arguments, returning an int
*/

int numcmp(char *, char *);

/* sort input lines */
int main (int argc, char *argv[])
{
	int nlines;
	int numeric = 0; // switch for numeric sort

	if (argc > 1 && strcmp(argv[1], "-n") == 0)
		numeric = 1;
	if ((nlines = reaadlines(lineptr, MAXLINES)) >= 0) {
		qsort((void**) lineptr, 0, nlines-1,
			(int (*) (void*, void*)) (numeric ? numcmp : strcmp));
		/*
		if -n flag is passed, use numcmp. ow use strcmp
		(int... void*)) casts numcmp and strcmp to the correct function pointer type
			for qsort
		(void**) lineptr casts char *lineptr[] to void *[], because qsort is written
			to be generic.
		*/
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("input too big to sort\n");
		return 1;
	}
}

void qsort(void *v[], int left, int right,
		int (*comp) (void *, void *))
{
	int i, last;

	void swap(void *v[], int, int);

	if (left >= right)
		return;
	swap(v, left, (left + right)/2);
	last = left;
	for (i = left+1; i <= right; i++)
		if ((*comp) (v[i], v[left]) < 0
			swap(v, ++last, i);
	swap(v, left, last);
	qsort(v, left, last-1, comp);
	qsort(v, last+1, right, comp);
}
