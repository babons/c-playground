#include <stdio.h>

#define NKEYS (sizeof keytab / sizeof (struct key))

struct key {
	char *word;
	int count;
} keytab[] = {
	"tree",0,
	"apple",0,
	"mango",0,
	"apricot",0,
	"dog",0,
	"cat",0,
	"hello",0,
	"goodbye",0,
	"welcome",0,
	"question",0,
	"mark",0
};

void inclookup(struct key keytab[], int n, char *word)
{
	for (int i = 0; i < n; i++) {
		if (keytab[i].word == word) {
			keytab[i].count++;
			return;
		}
	}
}

int main()
{
	char *word;
	printf("input a word: ");
	scanf("%s", &word);
	inclookup(keytab, NKEYS, word);

	printkeys();
	return 0;
}
