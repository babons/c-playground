#include <stdio.h>
#define ALLOCSIZE 10000
#define MAXWORD 10000
/*
Storage allocator. Figuring this out w/o textbook example (little of gpt
for high level *learning enhancements*).

This program will utilize storage allocating functions for short string
input.
*/

static char allocbuf[ALLOCSIZE]; /* storage for allo */
static char *allocp = allocbuf; /* pointer to the next free position*/ 
void afree(char *p); /* releases storage */
void inputwords(char *p);
void printwords(char *p);

int main()
{
	char c;
	int input;

	for (;;) {
		printf("1. Input\n2. Print\n3. Clear\n4. Exit\n");
		printf("Enter option: ");
		scanf("%i", &input);

		// GPT helped w/ syntax errors
		switch (input) {
			case 1:
				inputwords(allocp);
				break;
			case 2:
				printf("\nOutput:\n");
				printwords(allocp);
				break;
			case 3:
				afree(allocp);
				break;
			case 4:
				return 0;
			default:
				printf("\nhuh?\n");
				while (getchar() != '\n');

		}
	}
	return 0;
}
// Clears the buffer
void afree(char *p)
{
	// GPT helped with pointer rewind logic
	while (p != allocbuf) {
		*p = '\0';
		p--;
	}
	*p = '\0';
	allocp = allocbuf;
	printf("\n");
	return;
}


// Prints words collected and stored in the buffer
void printwords(char *p)
{
	int inputcount = 1;
	*(p-1) = '\0';
	p = allocbuf;

	if (*p == '\0') {
		printf("Buffer empty. Please enter some words with option 1.\n\n");
		return;
	}


	printf("%d: ", inputcount);
	while (*p != '\0') {
		if (*p == '#') {
			printf("\n");
			inputcount++;
			printf("%d: ", inputcount);
		} else if (*p == '|') {
			printf(" ");
		} else {
			printf("%c", *p);
		}
		p++;
	}
	printf("\n\n");
	return;
}

// Collects input and stores the words into the buffer. End of the input is marked by '|'
void inputwords(char *p)
{
	char c;
	while (getchar() != '\n');

        printf("Enter three words: ");
        while((c = getchar()) != '\n') {
		if (p - allocbuf >= ALLOCSIZE - 1) {
			printf("Buffer full. Please clear!\n");
			break;
                } else if (c == ' ') {
                        *p = '|';
                        p++;
                } else {
                        *p = c;
                        p++;
                }
        }
	*p = '#';
	p++;
	*p = '\0'; // will be overwritten if needed
	allocp = p;
	return;
}
