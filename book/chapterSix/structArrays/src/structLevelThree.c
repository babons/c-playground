#include <stdio.h>
#define NPOINTS (sizeof points / sizeof(struct point))
#define NKEYS (sizeof keys / sizeof (struct key))

struct point {
	int x,y;
} points[] = {
	1,2,
	3,4,
	5,6,
	7,8,
	9,10
};

struct key {
	char* word;
	int count;
} keys[] = {
	"clear",0,
	"write",0,
	"word",0,
	"meow",0,
	"memory",0,
};

void shiftpoints(struct point points[], int n, int dx, int dy)
{
	points[n].x += dx;
	points[n].y += dy;
}

void incwordcount(struct key keys[], int n, char *target)
{
	for (int i = 0; i < n; i++) {
		if (keys[i].word == target) {
			keys[i].count++;
		}
	}
}

void printpoints()
{
        for (int i = 0; i < NPOINTS; i++) {
                printf("%d, %d\n", points[i].x, points[i].y);
        }
	printf("\n");
}

void printcounts()
{
	for (int i = 0; i < NKEYS; i++) {
		printf("%s, %d\n", keys[i].word, keys[i].count);
	}
	printf("\n");
}

int main()
{
	printpoints();

	// Manip struct array
	shiftpoints(points, 0, 10, 10);
	printpoints();

	// String array / String array manip
	printcounts();
	incwordcount(keys, NKEYS, "clear");
	printcounts();
	return 0;
}
