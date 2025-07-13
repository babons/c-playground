#include <stdio.h>

/*
Demo structures and stuff. Level 1 of GPT's ringer
*/

struct point {
	int x, y;
};

struct point make_point(int x, int y);
void move_by_value(struct point *p, int dx, int dy);

int main()
{
	//!!! defining and using a simple struct
//	struct point {
//		int x,y;
//	};

	struct point p = {3, 4};

	// printf("%d, %d\n", p.x, p.y);

	//!!! struct pointers
	struct point *pp = &p;

	//printf("%d, %d\n", pp->x, pp->y);

	//!! struct functions
	struct point a = make_point(2, 5);
	printf("%d, %d\n", a.x, a.y); // 2, 5

	//!! passing a struct into a function
	struct point *pa = &a;
	move_by_value(pa, 5, 2);
	printf("%d, %d\n", a.x, a.y);
}

struct point make_point(int x, int y)
{
	struct point p;
	p.x = x;
	p.y = y;
	return p;
}

void move_by_value(struct point *p, int dx, int dy)
{
	p->x += dx;
	p->y += dy;
}
