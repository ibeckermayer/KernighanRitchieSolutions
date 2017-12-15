#include <stdio.h>
#define ALLOC 100
void strcpy2(char *s, char *t, int n);
void strcat2(char *s, char *t, int n);
int strcmp2(char *s, char *t, int n);

int main() 
{
  char s[ALLOC];
  char t[ALLOC] = "123456";
  int i;
  for (i = 1; i < 8; i++) {
    strcpy2(s, t, i);
    printf("strcpy: n = %d, %s\n", i, s);
  }

  putchar('\n');

  char s2[ALLOC] = "test ";
  char t2[ALLOC]="123456";
  for (i = 1; i < 8; i++) {
    strcat2(s2, t2, i);
    printf("strcat: n = %d, %s\n", i, s2);
    strcpy2(s2, "test ", 5);
  }

  putchar('\n');

  char s3[ALLOC] = "abcdef";
  char t3[ALLOC] = "abcghi";
  for (i = 1; i < 8; i++) {
    printf("strcmp: n = %d, %d\n", i, strcmp2(s3, t3, i));
    printf("strcmp: n = %d, %d\n", i, strcmp2(t3, s3, i));
  }
}

void strcpy2(char *s, char *t, int n)
{
  int inc = 0;
  while((*s++ = *t++) != '\0' && inc++ < n)
    ;
  *--s = '\0';
}

void strcat2(char *s, char *t, int n)
{
  while (*s != '\0')
    s++;

  int inc = 0;
  while ((*s++ = *t++) != '\0' && inc++ < n)
    ;
  *--s = '\0';
}

int strcmp2(char *s, char *t, int n)
{
  int inc = 1;
  for ( ; *s == *t && inc++ < n; ) {
    if (*s == '\0')
      return 0;
    s++;
    t++;
  }
  return *s - *t;
}
