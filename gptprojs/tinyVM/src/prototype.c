#include <stdio.h>
#include "operations.h"

/*
High-level prototype for this project.
*/

enum {
	HALT,
	LOAD,
	ADD,
	PRINT
};

int state = 1;
int acc = 0;
int pc = 0;

int main()
{
	void (*ptr[]) (int) = {halt, load, add, print};
	int programOne[][2] = {
		{LOAD, 6},
		{ADD, 3},
		{PRINT, 0},
		{HALT, 0}
	};

	while (state == 1) {
		ptr[programOne[pc][0]](programOne[pc][1]);
		pc++;
	}
}
