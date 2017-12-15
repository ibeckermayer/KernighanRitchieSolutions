#include <ctype.h>
#include <stdio.h>
#define MAX 100

int getch(void);
void ungetch(int);
double getfloat(double *pn);

int main() {
  double *pn;

  while (getfloat(pn) != EOF)
    printf("%f\n", *pn);
}

double getfloat(double *pn)
{
  int c, sign;

  while (isspace(c = getch()))
    ;
  if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
    ungetch(c);
    return 0;
  }
  sign = (c == '-') ? -1 : 1;
  if (c == '+' || c == '-') {
    c = getch();
    if (!isdigit(c)) {
      ungetch((sign == 1) ? '+' : '-');
      return 0;
    }
  }
  for (*pn = 0; isdigit(c); c = getch())
    *pn = 10.0 * *pn + (c - '0');
  if (c == '.') {
    c = getch();
    double div;
    for(div = 10.0; isdigit(c); c = getch(), div *=10.0)
      *pn = *pn + (c - '0') / div;
  }
  *pn *= sign;
  if (c != EOF)
    ungetch(c);
  return c;
}

int bufp = 0;
int buf[MAX];

int getch(void)
{
  return bufp > 0 ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
  if (bufp < MAX)
    buf[bufp++] = c;
}
