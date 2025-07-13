#include <stdio.h>

/*
Challenge covering lvlOne (check that source file). ChatGPT gave the tasks, I complete them.
*/

struct point {
	int x,y;
};

struct rectangle {
	struct point ul, lr;
};

void move_rectangle(struct rectangle *r, int dx, int dy);
void print_rectangle_points(struct rectangle r); // did not want to type that print twice.

int main()
{
	struct point upperLeft = {2, 5};
	struct point lowerRight = {5, 2};

	struct rectangle r = {upperLeft, lowerRight};
	struct rectangle *pr = &r;

	print_rectangle_points(r);
	move_rectangle(pr, 5, 5);
	print_rectangle_points(r);

	return 0;
}

void move_rectangle(struct rectangle *r, int dx, int dy)
{
	r->ul.x += dx;
	r->lr.x += dx;

	r->ul.y += dy;
	r->lr.y += dy;
}

void print_rectangle_points(struct rectangle r)
{
	printf("Rectangle points:\nUpper Left: %d, %d\nLower Right: %d, %d\n",
                r.ul.x, r.ul.y, r.lr.x, r.lr.y);
}
