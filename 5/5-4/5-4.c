#include <stdio.h>
int strend(char *s, char *t);
int strlen2(char *s);

int main()
{
  char s[] = "tester";
  char t1[] = "ester";
  char t2[] = "est";
  char t3[] = "testern";
  char t4[] = "ter";

  printf("1 = %d\n", strend(s, t1));
  printf("0 = %d\n", strend(s, t2));
  printf("0 = %d\n", strend(s, t3));
  printf("1 = %d\n", strend(s, t4));
}

int strend(char *s, char *t) 
{
  int strlens, strlent;
  strlens = strlen2(s);
  strlent = strlen2(t);

  if (strlens < strlent)
    return 0;

  s += strlens - strlent;
  while (*s++ == *t++)
    ;

  if (*s == '\0')
    return 1;
  else
    return 0;
}

int strlen2(char *s)
{
  char *p = s;
  while(*p != '\0')
    p++;
  return p - s;
}
