#include <stdio.h>
#include "operations.h"
#include "opcodes.h"

/*
High-level prototype for this project.
*/

int state = 1;
int acc = 0;
int pc = 0;

int main()
{
	void (*ptr[]) (int) = {halt, load, add, print};

	while (state == 1) {
		ptr[programOne[pc][0]](programOne[pc][1]);
		pc++;
	}
}
