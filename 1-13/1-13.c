#include <stdio.h>

#define IN  1
#define OUT 0
#define MAXWORDLENGTH 9
#define MAXOCCURENCES 10
#define BARSYMBOL '%'

main()
{
  int i, j, c, state, wlengthbuf;
  int wlength[MAXWORDLENGTH]; /*assume no words longer than 10 letters*/
  
  for (i= 0 ; i < MAXWORDLENGTH; ++i) {
    wlength[i]=0;
  }

  state = OUT;
  while((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      state = OUT;
      wlength[wlengthbuf-1]=wlength[wlengthbuf-1]+1;
      wlengthbuf=0;
    }
    else {
      state = IN;
      wlengthbuf++;
    }
  }
  
  /*for brevity, assume there are no more than MAXOCCURENCES of a word of a certain length*/
  for (j = MAXOCCURENCES ; j >= 0; j=j-1) {
    if (j == 0) {
       for (i = 0; i <= MAXWORDLENGTH; ++i) {
	 if (i==MAXWORDLENGTH)
	   putchar('\n');
	 else
	   putchar(i+'1');
       }
    }
    else {
      for (i = 0; i < MAXWORDLENGTH; ++i) {
	if (wlength[i]>=j)
	  putchar(BARSYMBOL);
	else
	  putchar(' ');

	if (i == MAXWORDLENGTH-1)
	  putchar('\n');
      }
    }
  }
}
