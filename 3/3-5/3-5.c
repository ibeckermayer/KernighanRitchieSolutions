#include <stdio.h>
#include <string.h>
#include <limits.h>

void reverse(char s[]) {
  int length = strlen(s);
  int c, i, j;

  for (i = 0, j = length - 1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

void itob(int n, char s[], int b) {

  int i, sign;
  unsigned int n2;
  i = 0;


  if ((sign = n) < 0) {
    n2 = -n;
  }
  else {
    n2 = n;
  }

  do {
    int dig;
    if ((dig = n2 % b) < 10)
      s[i++] = dig + '0';
    else
      s[i++] = dig + 'A'-10;
  }
  while ((n2 /= b) > 0);
  if (sign < 0) {
    s[i++] = '-';
  }
  s[i] = '\0';

  reverse(s);


}


int main() {
  char s[128];
  int i;
  int b = 2;
  for (i=0;i<=32;i++) {
    itob(i, s, b);
    printf("%2d is converted to %6s in base %d.\n", i, s, b);
  }

}
