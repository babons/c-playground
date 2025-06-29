#include <stdio.h>

int main() {
	char word[6] = {'h', 'e', 'l', 'l', 'o', '\0'}; // manual
	char greeting[] = "hello"; // shorthand version

	printf("%s\n", word); // will print each character stored in word together
	printf("%s\n", greeting); // will do the same with greeting
	printf("%c\n", greeting[1]); // prints 'e'

	return 0;
}
