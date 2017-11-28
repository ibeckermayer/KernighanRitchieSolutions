#include <stdio.h>
#define TABLENGTH 4
int main()
{
  int c,d,e,f;
  while((c=getchar()) != EOF){
    if (c==' '){
      d = getchar();
      e = getchar();
      f = getchar();
      if (d == EOF)
	putchar(c);
      else if (e == EOF){
	putchar(c);
	putchar(d);
      }
      else if (f == EOF) {
	putchar(c);
	putchar(d);
	putchar(e);
      }
      else {	
	if (d == ' ' && e == ' ' && f == ' ')
	  putchar('\t');
	else {
	  putchar(c);
	  putchar(d);
	  putchar(e);
	  putchar(f);
	}
      }
    }
    else
      putchar(c);
  }
  putchar('\n');
  return 0;
}
  
