#include <stdio.h>

/*
Program depicting bit shifts
*/

void print_binary(unsigned x);

int main()
{
	unsigned x = 255;
	int p = 4, n = 3;
	int shift = p + 1 - n;

	printf("Original value of x: %u\n", x);
	printf("Binary of x:		");
	print_binary(x);


       // Shift x right
    	unsigned shifted = x >> shift;
    	printf("\nShifted x >> %d:      %u\n", shift, shifted);
    	printf("Binary:              ");
    	print_binary(shifted);

    	// Create mask: ~(~0 << n)
    	unsigned mask = ~(~0 << n);
    	printf("\nMask (n = %d):        %u\n", n, mask);
    	printf("Binary:              ");
    	print_binary(mask);

    	// Apply mask
    	unsigned result = shifted & mask;
    	printf("\nResult:              %u\n", result);
    	printf("Binary:              ");
    	print_binary(result);
	return 0;
}

void print_binary(unsigned x)
{
	for (int i = 7; i >= 0; i--) {
		putchar((x & (1 << i)) ? '1' : '0');
	}
	putchar('\n');
}
