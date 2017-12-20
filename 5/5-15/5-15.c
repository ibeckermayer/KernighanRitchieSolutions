#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAXLINES 5000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], char lines[], int maxlines);
void writelines(char *lineptr[], int nlines);
void qsort2(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(char *, char *);
void reverse(void *lineptr[], int nlines);
#define MAXLEN 1000
int getline2(char *, int);

int main(int argc, char *argv[]) 
{
  int nlines, c;
  char lines[MAXLINES*MAXLEN];
  int numeric = 0;
  int rev = 0;
  int fold = 0;

  while (--argc > 0 && (*++argv)[0] == '-')
    while (c = *++argv[0])
      switch (c) {
      case 'n':
	numeric = 1;
	break;
      case 'r':
	rev = 1;
	break;
      case 'f':
	fold = 1;
	break;
      default:
	printf("sort: illegal option %c\n", c);
	argc = -1;
     	break;
      }

  if (argc != 0) {
    printf("Usage: sort [-n] [-r] [-f] < file\n");
    return 1;
  }
  else
    if ((nlines = readlines(lineptr, lines, MAXLINES)) >= 0) {
      qsort2 ((void **) lineptr, 0, nlines-1,
	      (int (*)(void*,void*))(numeric ? numcmp : fold ? strcasecmp:strcmp));
      if (rev)
	reverse((void **) lineptr, nlines); 
      writelines(lineptr, nlines);
      return 0;
    } else {
      printf("input too big to sort\n");
      return 1;
    }
}

void reverse(void *lineptr[], int nlines)
{
  int i, j;
  void *c;

  for (i = 0, j = nlines-1; i<j; i++, j--) {
    c = lineptr[i];
    lineptr[i] = lineptr[j];
    lineptr[j] = c;
  }
}

int numcmp(char *s1, char *s2)
{
  double v1, v2;

  v1 = atof(s1);
  v2 = atof(s2);
  if (v1<v2)
    return -1;
  else if (v1>v2)
    return 1;
  else
    return 0;
}

void swap(void *v[], int i, int j)
{
  void *temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

void qsort2(void *v[], int left, int right,
	   int (*comp)(void *, void *))
{
  int i, last;
  void swap(void *v[], int, int);

  if (left >= right)
    return;
  swap(v, left, (left + right)/2);
  last = left;
  for (i = left+1; i<=right; i++)
    if ((*comp)(v[i], v[left]) < 0)
      swap(v, ++last, i);
  swap(v, left, last);
  qsort2(v, left, last-1, comp);
  qsort2(v, last+1, right, comp);
}

void writelines(char *lineptr[], int nlines)
{
  int i;

  for (i = 0; i < nlines; i++)
    printf("%s\n", lineptr[i]);
}

int readlines(char *lineptr[], char *lines, int maxlines)
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
