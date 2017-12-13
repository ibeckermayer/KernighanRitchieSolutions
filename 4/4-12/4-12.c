#include <stdio.h>
#define MAX 1000

void itoa(int n, char s[]);
int i = 0;

int main()
{
  char s[1000];
  itoa(-1263, s);
  printf("%s\n", s);

}

void itoa(int n, char s[])
{
  if (n < 0) {
    n = -n;
    s[i++] = '-';
  }
  if (n / 10)
    itoa (n/10, s);
  s[i++] = n % 10 + '0';
  if (!(n/10))
    s[i] = '\0';
}
