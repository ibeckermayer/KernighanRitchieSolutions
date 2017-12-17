#include <stdio.h>
#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;
static int argp = 1;			/* which argv program is looking at */
static int argpp = 0;		/* which char in current argv to look at */
 
char getchar2(int argc, char *argv[])
{
  if (argp == argc-1 && argv[argp][argpp] == '\0')
    return EOF;
  else if (argv[argp][argpp] == '\0') {
    argp++;
    argpp = 0;
    return '\0';
  }
  else
    return argv[argp][argpp++];
}

int getch(int argc, char *argv[]) 
{
  return (bufp > 0) ? buf[--bufp] : getchar2(argc, argv);
}

void ungetch(int c)
{
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}


