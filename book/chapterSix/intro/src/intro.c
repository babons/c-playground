#include <stdio.h>

/*
Demo structures and stuff
*/

int main()
{
	struct point {
		int x,y;
	};

	struct point p = {3, 4};

	printf("%d, %d\n", p.x, p.y);
}
