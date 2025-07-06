#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int my_getline(char *s, int max);

int main(int argc, char *argv[])
{
	char line[MAXLINE];
	int found = 0;

	if (argc != 2)
		printf("Usage: find pattern\n");
	else
		while (my_getline(line, MAXLINE) > 0)
			// strstr returns a pointer to the first occurence of a string in a string.
			if (strstr(line, argv[1]) != NULL) {
				printf("%s", line);
				found++;
			}
	return found;
}

int my_getline(char *s, int max)
{

        int i = 0;
        int c;
        // char temp[lim];
        while ((c = getchar()) && c != EOF && c != '\n' && i < max) {
                s[i++] = c;
        }

        if (c == '#') {
                return 0;
        }
        //strcpy(s, temp);
        s[i++] = '\0';
        return i;
}
