#include <stdio.h>

struct point {
	int x,y;
} points[] = {
	1,2,
	3,4,
	5,6,
	7,8,
	9,10
};

int pointsize = sizeof(struct point);
int arraysize = sizeof points;

int main()
{
	return 0;
}
