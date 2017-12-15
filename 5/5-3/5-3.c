#include <stdio.h>
void strcat2(char *s, char *t);

int main()
{
  char s[] = "concat";
  char t[] = "enate";
  strcat2(s, t);
  printf("%s\n", s);
}

void strcat2(char *s, char *t) 
{
  while (*s != '\0')
    s++;
  while ((*s++ = *t++) != '\0')
    ;
}
