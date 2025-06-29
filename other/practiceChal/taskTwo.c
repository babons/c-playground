#include <stdio.h>

/*
This is a small program which will print each character of a string
one by one. It will stop at a null terminator

NOTE: This is also a great example of how the stack grows downwards,
but when the program is executed it walks forward.

Word[] is declared first, giving it a higher spot in memory. wordTwo[]
is declared after, giving it a lower place in memory.

When printing wordTwo, though, it can be seen that since wordTwo[] is
stored before word[], it keeps stepping forward until the null terminator
(\0) is found.
*/

int main() {
	char word[] = "word";
	printf("%p\n", &word);
	printf("%s\n", word);

	char wordTwo[6] = {'h', 'e', 'l', 'l', 'o', 'o'};
	for (int i = 0; i < 5; i++) {
		char* p = &wordTwo[i];
		printf("%p\n", (void*)p);
	}
	printf("%p\n", &word);
	printf("%s\n", wordTwo);

	return 0;
}
