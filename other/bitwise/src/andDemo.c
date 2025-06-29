#include <stdio.h>

int main() {
	int n = 254;
	printf("%d\n", n & 0177); // sets all but the low-order 7 bits to 0
	return 0;
}
