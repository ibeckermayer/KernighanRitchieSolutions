#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAXLINES 5000

char *lineptr[MAXLINES];

int readlines2(char *lineptr[], char lines[], int maxlines);

#define MAXLEN 1000
int getline2(char *, int);

int main(int argc, char *argv[]) 
{
  int nlines;
  char lines[MAXLINES*MAXLEN];
  int n = 10;

  printf("%s\n", *(argv+1));
  nlines = readlines2(lineptr, lines, MAXLINES);
  printf("%s\n", *(lineptr));
 }

int readlines2(char *lineptr[], char *lines, int maxlines)
{
  int len, nlines;
  char *p, line[MAXLEN];

  p = lines;
  nlines = 0;
  while ((len = getline2(line, MAXLEN)) > 0)
    if (nlines >= maxlines || p+len-lines > MAXLEN * maxlines)
     return -1;
    else {
      line[len-1] = '\0';
      strcpy(p, line);
      lineptr[nlines++] = p;
      p += len+1;
    }
  return nlines;
}


/* getline2: get line into s, return length */
int getline2(char *s, int lim)
{
  char *p;
  int c;

  p = s;
  while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    *p++ = c;
  if (c == '\n')
    *p++ = c;
  *p = '\0';
  return (int)(p - s);
}
