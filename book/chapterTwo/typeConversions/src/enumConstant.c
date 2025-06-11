#include <stdio.h>

/*
An enumeration is alist of constant integer values
*/

int main()
{
	enum boolean { NO, YES }; // First name has value 0, second 1, so on so forth

	enum escapes { BELL = '\a', BACKSPACE = '\b'} // Define custom values for each name
	enum months { JAN = 1, FEB, MAR, APR} // Set the start value, then increments

	// Adv over usage of #define is values are automatically assigned.
	// Compilers do not need to check if what is stored is a valid value for enumeration

	// Debuggers mau be able to print values of enum vars in their symbolic form
}
