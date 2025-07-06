#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int my_getline(char *s, int max);

int main(int argc, char *argv[])
{
	char line[MAXLINE];
	long lineno = 0;
	int c, except = 0, number = 0, found = 0;

	while (--argc > 0 && (*++argv) [0] == '-'){
		while ((c = *++argv[0])) {
			switch (c) {
			case 'x':
				except = 1;
				break;
			case 'n':
				number = 1;
				break;
			default:
				printf("find: illegal options %c\n", c);
				argc = 0;
				found = -1;
				break;
			}
		}
	}
	if (argc != 1) {
		printf("Usage: find -x -n pattern\n");
	} else {
		while (my_getline(line, MAXLINE) > 0) {
			lineno++;
			if ((strstr(line, *argv) != NULL) != except) {
				if (number){
					printf("%ld:", lineno);
				}
				printf("%s\n", line);
				found++;
			}
		}
	}
	return found;
}

int my_getline(char *s, int lim)
{
        int i = 0;
        int c;

        while ((c = getchar()) && c != EOF && i < lim) {
                if (c == '\n') {
			s[i++] = c;
			break;
		}
		s[i++] = c;
        }

	s[i] = '\0';
	return i;

        s[i] = '\0';
        return i;
}
