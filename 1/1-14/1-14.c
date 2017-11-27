#include <stdio.h>

#define IN  1
#define OUT 0
#define MAXOCCURENCES 30
#define CHAR_START 32
#define CHAR_STOP 126
#define BARSYMBOL '%'

main()
{
  const int CHAR_DIFF = CHAR_STOP-CHAR_START+1;
  int i, j, c;
  int charcount[CHAR_DIFF]; /*assume no words longer than 10 letters*/
  
  for (i= 0 ; i < CHAR_DIFF; ++i) {
    charcount[i]=0;
  }

  while((c = getchar()) != EOF) {
    charcount[c-CHAR_START]++;
  }
  
  /*for brevity, assume there are no more than MAXOCCURENCES of a word of a certain length*/
  for (j = MAXOCCURENCES ; j >= 0; j=j-1) {
    if (j == 0) {
       for (i = 0; i <= CHAR_DIFF; ++i) {
	 if (i==CHAR_DIFF)
	   putchar('\n');
	 else
	    putchar(i+CHAR_START);
       }
    }
    else {
      for (i = 0; i < CHAR_DIFF; ++i) {
	if (charcount[i]>=j)
	  putchar(BARSYMBOL);
	else
	  putchar(' ');

	if (i == CHAR_DIFF-1)
	  putchar('\n');
      }
    }
  }
}
