#include <stdio.h>
#include <time.h>

int rand(void);
void srand(unsigned int seed);

static unsigned int next = 1;

int main()
{
	srand((unsigned int)time(NULL));
	int r = rand();

	printf("%d", r);
}

/* returns a psueod-random integer on 0..32767 */
int rand(void)
{
	next = next * 110351524 + 12345;
	return (unsigned int) (next/65536) % 32768;
}

/* sets the seed for rand() */
void srand(unsigned int seed)
{
	next = seed;
}
