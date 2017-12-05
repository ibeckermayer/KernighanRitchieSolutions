#include <stdio.h>
int any (char s[], char ss[]);
int is_in(char c, char ss[]);

int main()
{
  char s[100]  = "0123456";
  char ss[100] = "426";
  char sss[100] = "a";
  printf("\n%d (should print 2)\n", any(s,ss));
  printf("%d (should print -1)\n\n", any(s,sss));
}


int any (char s[], char ss[])
{
  int i;

  for (i = 0; s[i] != '\0'; i++)
    if (is_in(s[i], ss))
      return i;
  return -1;
}

int is_in(char c, char ss[])
{
  int i;

  for (i = 0; ss[i] != '\0'; i++)
    if (ss[i]==c)
      return 1;
  return 0;
}
