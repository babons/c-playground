#include <stdio.h>
#define BUFSIZE 2048
#define INPUTBUF 256

/*
Storage allocator. Figuring this out w/o textbook example (little of gpt
for high level *learning enhancements*).

This program will utilize storage allocating functions for short string
input.
*/

static char allocbuf[BUFSIZE]; /* storage for allo */
static char *allocp = allocbuf; /* pointer to the next free position*/ 
char* alloc(int n);
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
				char *r = alloc(INPUTBUF);
				if (r == NULL) {
					printf("error: Buffer full. Please clear.\n\n");
					break;
				} else {
					printf("Enter your words: ");
					inputwords(r);
					printf("\n");
				}
				break;
			case 2:
				if (allocp == allocbuf) {
					printf("error: Buffer is empty. Please input words.\n\n");
					break;
				} else {
					printf("\nOutput:\n");
					printwords(allocbuf);
					break;
				}
			case 3:
				if (allocp == allocbuf) {
					printf("error: Buffer is empty. Nothing to clear!\n");
				}
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

// Allocates n bytes for input and returns a pointer at the start of this block

char* alloc(int n)
{
	if (allocbuf + BUFSIZE - allocp >= n) {
		char *start = allocp;
		allocp += n;
		return start;
	} else {
		return NULL;
	}
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
	// re-writing this bc fixing it after alloc addition is pissing me off
	char *b = p;
	int entrycount = 1;
	while (b < allocp) {
		if (*b == '\0') break; // no additional entries

		printf("%d: ", entrycount++);

		for (char *c = b; *c != '\0' && c < b + INPUTBUF; c++) {
			if (*c == '|') {
				printf(" ");
			} else
				printf("%c", *c);
		}

		printf("\n");
		b += INPUTBUF;
	}

	printf("\n");
}

// Collects input and stores the words into the buffer. End of the input is marked by '|'
void inputwords(char *p)
{
	char c;
	while (getchar() != '\n');

        while((c = getchar()) != '\n') {
		if (p == (allocp - 1)) {
			printf("\nerror: buffer filled at: %c.\n", *(p-1));
			*(p-1) = '#';
			return;
		} else if (c == ' ') {
                        *p = '|';
                        p++;
                } else {
                        *p = c;
                        p++;
                }
        }
	return;
}
