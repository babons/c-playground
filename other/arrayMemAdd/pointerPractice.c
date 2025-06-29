#include <stdio.h>

int main() {
	int x = 5;
	int *p = &x; // p points to x

	printf("x = %d\n", x);	// will print 5 (x's value)
	printf("p = %p\n", (void*)p); // will print the address where x is stored
	printf("*p = %d\n", *p); // will print 5, the value pointed to by p

	*p = 99; // sets x to 99 through the pointer
	printf("x = %d\n", x);
	return 0;
}
