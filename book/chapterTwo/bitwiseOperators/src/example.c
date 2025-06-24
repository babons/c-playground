#include <stdio.h>

int main()
{
	int n = 128;
	printf("%d\n", n);
	printf("%d\n", n & 0177);
	printf("%d\n", n ^ 64);
	printf("%d\n", n << 1);
	printf("%d\n", n >> 1);
	printf("d\n", ~n);

	return 0;
}
