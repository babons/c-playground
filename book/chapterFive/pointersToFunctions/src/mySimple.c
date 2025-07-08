#include <stdio.h>

/*
My additions to previous simple.c to reinforce.
*/

int subtract(int a, int b) {
	return a - b;
}

int divide(int a, int b) {
	return a / b;
}

int operate(int a, int b, int (*op) (int, int)) {
	return op(a, b);
}

int main()
{
	int a,b,choice,result;
	int (*op) (int, int);
	printf("Please enter two numbers: ");
	scanf("%d %d", &a, &b);
	printf("Select an operation; 1 for subtract and 2 for divide: ");
	scanf("%d", &choice);

	if (choice == 1) {
		op = subtract;
	} else if (choice == 2) {
		op = subtract;
	} else {
		printf("wut\n");
	}

	result = operate(a,b,op);
	printf("%d\n", result);
}
