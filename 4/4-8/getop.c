#include <stdio.h>
#include <ctype.h>
#include "calc.h"

int getop(char s[])
{
  int i, c, d, e;
  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';
  if (!isdigit(c) && c != '.') {
    d = getch();
    e = getch();
    if (c == 's' && d == 'i' && e == 'n')
      return 128;
    if (c == 'c' && d == 'o' && e == 's')
      return 129;
    if (c == 'e' && d == 'x' && e == 'p')
      return 130;
    if (c == 'p' && d == 'o' && e == 'w')
      return 131;
    else
      return c;
  }
  i = 0;
  if (isdigit(c))
    while (isdigit(s[++i] = c = getch()))
      ;
  s[i] = '\0';
  if (c != EOF)
    ungetch(c);
  return NUMBER;
}
