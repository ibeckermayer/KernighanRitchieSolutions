#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAXLINES 5000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
int readlines2(char *lineptr[], char lines[], int maxlines);

#define MAXLEN 1000
int getline2(char *, int);
char *alloc(int);

int main() 
{
  clock_t start, end, start2, end2;
  double cpu_time_used, cpu_time_used2;
  
  int nlines;   
  start = clock();
  nlines = readlines(lineptr, MAXLINES);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

  char buf[MAXLINES*MAXLEN];
  start2 = clock();
  nlines = readlines2(lineptr, buf, MAXLINES);
  end2 = clock();
  cpu_time_used2 =  ((double) (end2 - start2)) / CLOCKS_PER_SEC;

  printf("K&R version took %.12f seconds to execute\nNew version took %.12f seconds to executre\n", cpu_time_used, cpu_time_used2);

}

int readlines(char *lineptr[], int maxlines)
{
  int len, nlines;
  char *p, line[MAXLEN];

  nlines = 0;
  while ((len = getline2(line, MAXLEN)) > 0)
    if (nlines >= maxlines || (p = alloc(len)) == NULL)
      return -1;
    else {
      line[len-1] = '\0';
      strcpy(p, line);
      lineptr[nlines++] = p;
    }
  return nlines;
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

#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n)
{
  if (allocbuf + ALLOCSIZE - allocp >= n) {
    allocp+=n;
    return allocp-n;
  } else
    return 0;
}
