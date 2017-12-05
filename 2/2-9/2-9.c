/* 
In a two's complement number system, -1 is represented by "...11111111..." 
When you subtract 1 in this system, you're actually adding this "all ones" number
to the minuend (let's call this X). That means that the first '1' in X becomes 0,
and then a '1' is carried through the rest of the number, keeping all of the more 
siginificant digits the same, and spills out into the overflow. If you do 'x &= (x-1)', 
you're simply deleting the first one in the number (and-ing these accounts for the 
0's that were inverted before hitting the first '1' in the subtraction)  
*/

#include <stdio.h>
int bitcount(unsigned x);

int main()
{
  int x = 50884;
  printf("bitcount of %d: %d\n", x, bitcount(x));
}

int bitcount(unsigned x)
{
  int i = 0;
  while((x &= (x-1)))
	++i;
  return ++i;
}
