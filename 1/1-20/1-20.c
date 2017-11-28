#include <stdio.h>
#define TABLENGTH 4
int main()
{
  int c;
  while((c=getchar()) != EOF){
    if (c=='\t'){
      int i;
      for (i=0;i<TABLENGTH;++i)
	putchar(' ');
      }
    else
      putchar(c);
  }
}
  
