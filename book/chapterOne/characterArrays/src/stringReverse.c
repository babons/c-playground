#include <stdio.h>
#define MAXINPUT 100000
/*
This program uses a reverse function to print the reverse of every line entered
*/
void reverse(char s[], int startingIndex);
void clear(char s[], int length);

int main()
{
	int c, i;
	char input[MAXINPUT];
	i = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\n') {
			reverse(input, i);
			printf("Reversed: %s\n", input);
			input[i] = '\0';
			clear(input, i);
		} else {
		input[i] = c;
		++i;
		}
	}

	// printf("\n Here are your strings:\n %s", input);

}

void reverse(char s[], int length)
{
	int i;
	char copy[length];
	for (i=0; i != length; ++i) {
		copy[i] = s[i];
	}
	for(i=0; i != length; ++i) {
		s[i] = copy[length - 1 - i];
	}
}

void clear(char s[], int length)
{
	int i;
	for (i=0; i < length; ++i)
	{
		s[i] = 0;
	}
}
