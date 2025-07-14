#include <stdio.h>
#define NPOINTS (sizeof points / sizeof(struct point))
struct point {
	int x,y;
} points[] = {
	1,2,
	3,4,
	5,6,
	7,8,
	9,10
};

void shiftpoints(struct point points[], int n, int dx, int dy)
{
	points[n].x += dx;
	points[n].y += dy;
}

void printpoints()
{
        for (int i = 0; i < NPOINTS; i++) {
                printf("%d, %d\n", points[i].x, points[i].y);
        }
	printf("\n");
}

int main()
{
	printpoints();

	// Manip struct array
	shiftpoints(points, 0, 10, 10);
	printpoints();

	return 0;
}
