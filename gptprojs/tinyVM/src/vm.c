#include <stdio.h>
#include "programs.h"
#include "opcodes.h"
#include "operations.h"

int state = 1;
int acc = 0;
int pc = 0;
int trace = 0;

void vmrun(int program[][2], int trace)
{
	state = 1;
	acc = 0;
	pc = 0;
	void (*ptr[])(int) = {halt, load, add, sub, print};
	while (state) {
		if (trace == 1) {
			if ((program[pc][0]) != 0) {
				printf("r: %d\n%d: %d, %d\n\n",
					acc, pc + 1, program[pc][0], program[pc][1]);
				ptr[program[pc][0]](program[pc][1]);
				pc++;
			} else {
				ptr[program[pc][0]](program[pc][1]);
				printf("Halt!\n");
			}
		} else {
			ptr[program[pc][0]](program[pc][1]);
                	pc++;
		}
	}
}
