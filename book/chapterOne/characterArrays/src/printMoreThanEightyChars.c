#include <stdio.h>
#define MAXLENGTH 100000
#define MAXLINE 1000 // Added this missing define

/*
This is a small program which prints all input lines which are longer than 80 characters
*/

int gline(char store[], int max);
void addToStore(char store[], char addition[], int lengthStore);

int main()
{
    int len;
    int min;
    int size;
    char line[MAXLENGTH];
    char store[MAXLENGTH];

    size = 0;
    min = 80;
    while ((len = gline(line, MAXLINE)) > 0)
    {
        if (len > min) {
            addToStore(store, line, size);
            size += len;
        }
    }

    for (int i = 0; i < size; ++i) { // changed lengthStore to size
        putchar(store[i]);
    }
    return 0; // added return for main
}

// Renamed this to gline to match your function call in main
int gline(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    // s[i] = '\0'; // commented out, as you're storing as a character array for printing
    return i;
}

void addToStore(char store[], char add[], int s)
{
    int i = 0;
    int j = s;
    while ((store[j] = add[i]) != '\0') // changed 'from' to 'add'
    {
        ++i;
        ++j; // increment j to actually store data at the right offset
    }
}
