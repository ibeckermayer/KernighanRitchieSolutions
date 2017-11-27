#include <stdio.h>

main() {
  int c;
  char lastchar;
  
  while ((c=getchar()) != EOF) {
    if (lastchar==' ' && c == ' ') {
      ;
	}
    else {
      putchar(c);
    }
    lastchar=c;
  }
}
