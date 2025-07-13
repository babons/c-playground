#include <stdio.h>
#include <string.h>
#include "ctype.h"
#include "operations.h"
#include "opcodes.h"
#include "programs.h"
#include "vm.h"

/*
High-level prototype for this project.
*/

int main(int argc, char *argv[])
{
	// argument handling
	int trace = 0;
	//if (argc > 1) {
	//	printf("too many arguments\n");
	//}
	if (argc == 2 && strcmp(argv[1], "-t") == 0) {
		printf("OPCODES: 0 HALT 1 LOAD 2 ADD 3 SUB 4 PRINT\n\n");
		trace = 1;
	}
	printf("Program One output:\n");
	vmrun(programOne, trace);
	printf("\nProgram Two output:\n");
	vmrun(programTwo, trace);
}
