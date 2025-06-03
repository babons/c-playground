#include <stdio.h>

/*
This is a small program which will print a variable's address,
assign its pointer, and change the value of it using a pointer.
*/

int main() {
	// print var address
	int x = 5;
	printf("x's memory address is: %p\n", &x);

	int* p = &x;
	*p = 10;
	printf("x's new value is: %d\n", x);
	return 0;
}
