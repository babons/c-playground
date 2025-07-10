#include <stdio.h>
#include "operations.h"
#include "opcodes.h"
#include "programs.h"
#include "vm.h"

/*
High-level prototype for this project.
*/

int main()
{
	printf("Program One output:\n");
	vmrun(programOne);
	printf("\nProgram Two output:\n");
	vmrun(programTwo);
}
