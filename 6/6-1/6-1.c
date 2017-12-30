#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define BUFSIZE 100
int getch(void);
void ungetch(int);
int getword(char *word, int lim);
int isvalidchar(char c);
int isskip(char c);
char buf[BUFSIZE];
int bufp = 0;

int main() 
{
  char word[BUFSIZE];
  while (getword(word, BUFSIZE) != EOF)
    printf("%s\n", word);
}

int isvalidchar(char c)
{
  if (isalnum(c) || c == '_')
    return 1;
  else
    return 0;

}

int isskip(char c)
{
  if (isspace(c))
    return 1;

  switch(c) {
  case '#' :
  case '/' :
  case '*' :
  case '<' :
  case '>' :
  case '\'':
  case '\"':
  case ';' :
  case '}' :
  case '{' :
  case '(' :
  case ')' :
  case '=' :
  case ':' :
    return 1;
  default :
    return 0;
  }
}

int getword(char *word, int lim)
{
  char *w = word;
  int c;

  while (isskip(c = getch()))
    ;
  if (c != EOF)
    *w++ = c;
  if (!isalpha(c)) {
    *w = '\0';
    return c;
  }
  for ( ; --lim > 0; w++)
    if (!isvalidchar(*w = getch())) {
      ungetch(*w);
      break;
    }
  *w = '\0';
  return word[0];
}

int getch(void)
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}
