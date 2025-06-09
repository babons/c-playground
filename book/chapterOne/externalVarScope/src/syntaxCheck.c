#include <stdio.h>
#define MAXFILESIZE 100000

/*
This is a program which will take a C Program as input and check the syntax of it.

Note: I am tired. I just left the checker for Curly Brackets. Logic is same for
	everything else. Maybe I will come back to it and allow it to catch
	mis-ordered symbols, maybe not. Maybe eventually.
*/

char program[MAXFILESIZE];
int length;

int checkCBracket();
int checkParan();

int main()
{
	int i, c;
	extern char program[];
	extern int length;

	length = 0;
	while ((c = getchar()) != EOF) {
		program[length] = c;
		++length;
	}

	printf("\n");
	if (checkCBracket() == 1) {
		printf("\nCurly Brakets are Clear!");
	} else {
		printf("\nProblem with your Curly Brakets.");
	}

	//if (checkParan() == 1) {
	//	printf("\nParantheses are Clear!");
	//} else {
	//	printf("\nProblem with your Parantheses.");
	//}
	printf("\n");
	return 0;
}

int checkCBracket()
{
	int i,j,detectLeft,detectRight;
	extern int length;
	extern char program[];

	i = detectLeft = detectRight = 0;
	while (i < length) {
		if (program[i] == '{') {
			detectLeft += 1;
			//j = i + 1;
			//while (j < length) {
			//	if (program[j] == '}') {
			//		detect = 0;
			//	}
			//	j++;
			}
		if (program[i] == '}') {
			detectRight += 1;
		}
		++i;
	}
	if (detectLeft == detectRight) {
		return 1;
	}
	return 0;
}
