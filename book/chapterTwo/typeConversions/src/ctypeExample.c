#include <stdio.h>
#include <ctype.h>

/*
ctype describes a family of functions which provide tests / conversion which are
independent of character set.
*/
int main()
{
	int c, checkA, checkB;
	checkA = checkB = 0;
	c = '5';

	if (c >= '0' && c <= '9') {
		checkA = 1;
	}

	if (isdigit(c)) {
		checkB = 1;
	}

	printf("Test results!\nCheckA: %d\nCheckB: %d\n", checkA, checkB);
	printf("Other test results!\nCheckConditional: %d\nCheckFunction: %d\n", 
		c >= '0' && c <= '9', isdigit(c)); // isdigit will return 2048, 'true-zero'
	return 0;
}
