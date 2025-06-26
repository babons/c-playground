#include <stdio.h>

/*
swap function -- swap two variables from the caller
*/

void swap(int *px, int *py);
int main()
{
	int x, y;
	printf("Enter two numbers: \n");
	scanf("%d %d", &x, &y);
	swap(&x, &y);
	printf("Swapped: %d, %d\n", x, y);
	return 0;
}

void swap(int *px, int *py)
{
	int temp = *px;
	*px = *py;
	*py = temp;
}
