#include <stdio.h>

/*
Program featuring a function strindex(s,t) which returns the position of the rightmost
occurence of t in s, or -1 if there is none
*/

int strindex(char s[], char t);

int main()
{
	char word[1000];
	char t;
	int r;
	printf("Enter your input: ");
	scanf("%s", word);
	while (getchar() != '\n');
	printf("Input: %s\n", word);

	printf("Enter which letter you want to look for: \0");
	scanf("%c", &t);
	r = strindex(word, t);
	if (strindex(word, t) == -1) {
		printf("No match.\n");
	} else {
		printf("Match found at: %d\n", r);
	}
	return 0;
}

int strindex(char s[], char t)
{
	int i = 0;
	int r = -1;
	while (s[i] != '\0') {
		if (s[i] == t) {
			r = i;
		}
		++i;
	}
	return r;
}
