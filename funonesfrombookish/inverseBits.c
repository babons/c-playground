#include <stdio.h>

/*
Program featuring an invert function which takes an unsigned integer, starting position integer,
and bit count to replace a set of bits with it's inverse.
*/

unsigned invert(unsigned x, int p, int n);

int main()
{
	unsigned x;
	int p, n;

	printf("Enter your number, starting position, and number of bits: ");
	scanf("%u%d%d", &x, &p, &n);

	printf("Inverted: %u\n", invert(x, p, n));
	return 0;
}

unsigned invert(unsigned x, int p, int n)
{
	unsigned mask = (~(~0 << n)) << (p+1-n);
	unsigned result = x ^ mask;
	printf("Number: %b\nMask: %b\nInverted: %b\n", x, mask, result);
	return result;
}
