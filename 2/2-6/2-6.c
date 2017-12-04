#include <stdio.h>
unsigned setbits(unsigned x, int p, int n, unsigned y);

int main()
{
  unsigned x, y;
  int p, n;

  // Test 1 
  x=183;
  y=76;
  p=4;
  n=3;
  printf("%u\n", setbits(x,p,n,y));

  // Test 2
  p=7;
  n=4;
  printf("%u\n", setbits(x,p,n,y));

}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
  unsigned a, b, mask;
  y <<= (p+1-n);
  a = ~(~0<<(p+1-n)); // rightmost p+1-n bits are 1
  b = ~0<<(p+1); //rightmost p+1 bits are 0
  mask = a+b;
  y = y & ~mask;
  x = x & mask;
  return x+=y;
}
