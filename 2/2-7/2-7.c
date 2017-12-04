#include <stdio.h>
unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, unsigned y);
unsigned invert(unsigned x, int p, int n);

int main()
{
  unsigned x;
  int p, n;

  // Test 1 
  x=47;
  p=n=5;
  printf("%u\n", invert(x,p,n));
}

unsigned getbits(unsigned x, int p, int n)
{
  return (x >> (p+1-n)) & ~(~0<<n);
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

unsigned invert(unsigned x, int p, int n)
{
  unsigned y = getbits(x,p,n);
  y = ~y;
  return setbits(x,p,n,y);
}
