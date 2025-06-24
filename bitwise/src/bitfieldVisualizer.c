#include <stdio.h>

/*
This is a program which visualizes the bitfield of a number
before and after bitwise operations.
*/

void printbinary(unsigned x);

int main()
{
	unsigned x, y, choice;
	printf("Enter a number: ");
	scanf("%u", &x);
	printbinary(x);

	printf("Choose an option (1-6): ");
	scanf("%d", &choice);

	if (choice == 1) {
		printf("Shifted 2 bits to the right: %u\n", x >> 2);
		printbinary(x >> 2);
	}

	if (choice == 2) {
		printf("Shifted 2 bits to the left: %u\n", x << 2);
		printbinary(x << 2);
	}

	if (choice == 3) {
		printf("One's compliment: %u\n", ~x);
		printbinary(~x);
	}

	if (choice == 4) {
		printf("Enter a number to AND the number to: ");
		scanf("%u", &y);
		printbinary(y);
		printf("AND'd to %u: %u\n", y, x & y);
		printbinary(x & y);
	}

	if (choice == 5) {
		printf("Enter a number to OR the number to: ");
		scanf("%u", &y);
		printbinary(y);
		printf("OR'd to %u: %u\n", y, x | y);
		printbinary(x | y);
	}

	if (choice == 6) {
		printf("Enter a number to EXCLUSIVE OR the number to: ");
		scanf("%u", &y);
		printbinary(y);
		printf("EXCLUSIVE OR'd to %u: %u\n", y, x ^ y);
		printbinary(x ^ y);
	}
	return 0;
}

void printbinary(unsigned x)
{
        for (int i = 7; i >= 0; i--) {
                putchar((x & (1 << i)) ? '1' : '0');
        }
        putchar('\n');
}
