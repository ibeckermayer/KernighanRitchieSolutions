#include <stdio.h>
#define TABLENGTH 4
int main()
{
   
  while((c=getchar()) != EOF){
    if (c=='') {
      d = getchar();
      if (d == '*') {
	while (((e=getchar()) != '*' && (f=getchar()) != '') || ((e=getchar()) != '' && (f=getchar()) != '*'))
	   ; 
	  putchar('\0');
      }
      else
	putchar(d);
    }
    else
      putchar(c);
  }
}
  
