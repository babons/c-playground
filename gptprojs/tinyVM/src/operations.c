#include <stdio.h>
#include "vm.h"

/*
Operations used by the vCPU
*/

extern int acc;
extern int state;

void load(int n)
{
	acc = n;
}

void add(int n)
{
	acc += n;
}

void sub(int n)
{
	acc -= n;
}

void print(int n)
{
	printf("%d\n", acc);
}

void halt(int n)
{
	state = 0;
}
