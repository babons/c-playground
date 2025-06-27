#include <stdio.h>

/*
Small program showing how Macro Substitution works
*/

#define forever for(;;)
#define max(A, B) ((A) > (B) ? (A) : (B))
#define swap(t, x, y) do { t time = x; x = y; y = time; } while (0)

int main()
{
//	forever
//		printf("Hello");
//	int n1, n2;
//	printf("Input two numbers: ");
//	scanf("%d %d", &n1, &n2);
//	printf("%d is higher\n", max(n1, n2));

	int a = 2, b = 7;
	swap(int, a, b);
	printf("swapped: %d, %d\n", a, b);
	return 0;
}
