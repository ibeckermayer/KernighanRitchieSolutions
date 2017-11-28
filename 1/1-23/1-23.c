#include <stdio.h>
#define TABLENGTH 4
int main()
{
  /* one type of comment */
  int c,d,e,f; /* another type of comment */
  while((c=getchar()) != EOF){
    if (c=='/') {
      d = getchar();
      if (d == '*') {
	while (((e=getchar()) != '*' && (f=getchar()) != '/') || ((e=getchar()) != '/' && (f=getchar()) != '*'))
	  /* printf("\ne=%c, f=%c\n", e, f) */
	  putchar('\0');
      }
      else
	putchar(d);
    }
    else
      putchar(c);
  }
}
  
