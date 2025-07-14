#include <stdio.h>

struct point {
	int x,y;
};

struct rectangle {
	struct point ul,lr;
};

struct rectangle makerectangle(struct point ul, struct point lr)
{
	struct rectangle r;
	r.ul = ul;
	r.lr = lr;

	return r;
}

void moverectangle(struct rectangle *r, int dx, int dy)
{
	r->ul.x += dx;
	r->lr.x += dx;
	r->ul.y += dy;
	r->lr.y += dy;
}

void modrectul(struct rectangle *r, int x, int y)
{
	struct point nul = {x, y};
	r->ul = nul;
}

int rectwidth(struct rectangle r) {return r.lr.x - r.ul.x;}

int rectheight(struct rectangle r) {return r.ul.y - r.lr.y;}

void printr(struct rectangle r)
{
        printf("Rectangle points:\nUpper Left: %d, %d\nLower Right: %d, %d\n\n",
                r.ul.x, r.ul.y, r.lr.x, r.lr.y);
}

int main()
{
	struct point ul = {3, 4};
	struct point lr = {5, 2};
	struct rectangle hello = makerectangle(ul, lr);

	printr(hello);

	moverectangle(&hello, 5, 5);
	printr(hello);

	printf("Rectangle has width: %d and height: %d\n\n",
		rectwidth(hello), rectheight(hello));

	modrectul(&hello, 3, 4);
	printr(hello);

	return 0;
}
