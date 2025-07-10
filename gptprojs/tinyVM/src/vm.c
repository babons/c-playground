#include <stdio.h>
#include "programs.h"
#include "opcodes.h"
#include "operations.h"

int state = 1;
int acc = 0;
int pc = 0;

void vmrun(int program[][2])
{
	state = 1;
	acc = 0;
	pc = 0;
	void (*ptr[])(int) = {halt, load, add, sub, print};
	while (state) {
		ptr[program[pc][0]](program[pc][1]);
                pc++;
	}
}
