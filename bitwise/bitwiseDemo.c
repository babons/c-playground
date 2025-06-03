#include <stdio.h>

/*
Learning program to understand bitwise operation
*/

int main() {
	// Representation of &ing;
	// a in binary is 1101 and b is 0110
	// 1101
	// 0110
	// 0100 (after &)
	int a = 13;
	int b = 6;
	int c = a & b;
	printf("13 and 6 and-ed: %d\n", c);

	// So long as a bit is present,
	// the bit carries over (1111)
	c = a | b;
	printf("13 and 6 or-ed: %d\n", c);

	// This is XOR
	// If only 1 bit is present in either, it passes.
	// If two are present (third bit), it gets 0-ed.
	// 1011 (11)
	c = a ^ b;
	printf("13 and 6 XOR-ed: %d\n", c);

	// NOT operator flips every bit:
	// 00001101 = 11110010 (0 becomes 1).
	// Two's compliment makes it so the values are inverted (above) and you add one.
	// so (Two's compliment) 11110010 = -(13 + 1).
	// Now, the highest bit acts as the "sign bit". This tells
	// the computer whether it is negative or not. 1 is yes.
	// When NOT is applied, that bit is flipped, so the number
	// becomes negative. (~n = -(n + 1).
	printf("13 NOT-ed: %d\n", ~a);

	// Bit Shift Left (<<)
	// 13 << 1
	// 00001101 -> 00011010 (26)
	printf("13 shifted left 1 bit: %d\n", 13 << 1);

	// Bit Shift Right (>>)
	// 13 >> 1
	// 00001101 -> 00000110 (6)
	printf("13 shifted right 1 bit: %d\n", 13 >> 1);
return 0;
}
