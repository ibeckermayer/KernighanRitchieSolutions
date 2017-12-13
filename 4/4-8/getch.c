#include <stdio.h>
#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;
char buf;

int getch(void)
{
  if (bufp) { 
    bufp--;
    return buf;
  }
  else
    getchar();
}

void ungetch(int c)
{
  buf = c;
  bufp++;
}
