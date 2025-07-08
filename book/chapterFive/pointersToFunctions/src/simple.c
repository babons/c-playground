#include <stdio.h>

/*
program suggested by chatgpt to experience function pointers before diving into the chapter
*/

/*
program which asks the user for two integers, choose to add or multiply them,
uses a function pointer to call the selected operation.
*/

int add(int a, int b) {
	return a + b;
}

int multiply(int a, int b) {
	return a * b;
}

int compute(int x, int y, int (*operation)(int, int)) {
	return operation(x, y);
	// operation points to a function which takes two int's and returns an int
	// like int operation(int x, int y)
}

int main()
{
	int a, b, choice;
	int (*op)(int, int);

	printf("Enter two integers: ");
	scanf("%d %d", &a, &b);

	printf("Choose operation: 1 for add, 2 for multiply: ");
	scanf("%d", &choice);

	if (choice == 1) {
		op = add; // points to add
	} else if (choice == 2) {
		op = multiply;
	} else {
		printf("Invalid choice.\n");
		return 1;
	}

	int result = compute(a, b, op);
	printf("Result: %d\n", result);

	return 0;
}
