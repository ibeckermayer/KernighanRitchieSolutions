#include <stdio.h>
unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, unsigned y);
unsigned invert(unsigned x, int p, int n);
unsigned rightrot(unsigned x, int n);

int main()
{
  unsigned x;
  int n;

  // Test 1 
  x = 10922;
  n = 6;
  printf("%u\n", rightrot(x,n));
}

unsigned rightrot(unsigned x, int n) 
{
  unsigned wrap = 0;
  for (int i = 0; i<n; i++)
    {
      wrap >>= 1;
      int is_lsb_1 = x & ~(~(unsigned) 0<<1);
      if (is_lsb_1)
	wrap += ~(~(unsigned) 0>>1);
      else
	;
      x>>=1;
    }
  x+=wrap;
  return x;
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
