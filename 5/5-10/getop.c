#include <stdio.h>
#include <ctype.h>
#include "calc.h"

int getop(char s[], int argc, char *argv[])
{
  int i, c, d, e;
  while ((s[0] = c = getch(argc, argv)) == ' ' || c == '\t' || c == '\0')
    ;
  s[1] = '\0';
  if (!isdigit(c) && c != '.') {
    d = getch(argc, argv);
    e = getch(argc, argv);
    if (c == 's' && d == 'i' && e == 'n')
      return 128;
    if (c == 'c' && d == 'o' && e == 's')
      return 129;
    if (c == 'e' && d == 'x' && e == 'p')
      return 130;
    if (c == 'p' && d == 'o' && e == 'w')
      return 131;
    else {
      ungetch(e);
      ungetch(d);
      return c;
    }
  }
  i = 0;
  if (isdigit(c))
    while (isdigit(s[++i] = c = getch(argc, argv)))
      ;
  s[i] = '\0';
  return NUMBER;
}
