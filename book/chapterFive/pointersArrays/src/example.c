#include <stdio.h>

int main()
{
	int a[10];
	int *pa;
	int x;
	a[0] = 10;
	a[1] = 11;

	pa = &a[0]; // Memory address of a[0]
	x = *pa; // copy contents of a[0] into x

	x = *(pa+1); // returns next value (a[1])
	// This addition to a pointer is relevant to all types and values

	// a[i] == *(a + i)
	// C converts a[i] to *(a+i)

	// Difference: Pointers are vars and array names are not
	// pa=a and pa++ are legal -- a=pa and a++ is illegal

	return 0;
}
