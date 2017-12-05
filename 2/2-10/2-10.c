#include <stdio.h>
int lower(int c);

int main() 
{
  char c = 'f';
  printf("f stays %c\n", lower(c));
  c = 'F';
  printf("F becomes %c\n", lower(c));
  return 0;
}

int lower(int c) 
{
  return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}
