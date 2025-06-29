#include <stdio.h>

/*
Program featuring a function setbits which returns input x with the n bits which begin
	at position p set to the rightmost n bits of y, leaving the other bits unchanged.
*/

unsigned setbits(unsigned x, unsigned y, int p, int n);

int main()
{
	unsigned x, y;
	int n, p;
	printf("Enter input one: ");
	scanf("%u", &x);
	printf("Enter input two: ");
	scanf("%u", &y);
	printf("Enter where you which bit you want to start replacement: ");
	scanf("%d", &p);
	printf("Enter the amount of bits you would like to replace in input one with input two: ");
	scanf("%d", &n);

	printf("Output: %d\n", setbits(x, y, p, n));

	return 0;
}

unsigned setbits(unsigned x, unsigned y, int p, int n)
{
	unsigned replacementbits = (y & ~(255 << n)) << n - 1;
	unsigned clearedx = (~(~0 << n) << p+1-n);

	printf("\nOutput: %b\n", (x & ~clearedx) | replacementbits);
	return (x & ~clearedx) | replacementbits;
}
