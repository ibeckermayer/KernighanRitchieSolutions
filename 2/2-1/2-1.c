// inspiration taken from http://clc-wiki.net/wiki/K%26R2_solutions:Chapter_2:Exercise_1 
/* calculate the ranges of various types */
#include <stdio.h>
#include <limits.h>

int main(void)
{
  /* integer types */
	unsigned char c;
	unsigned int i;
	unsigned short s;
	unsigned long l;
	unsigned long long ll;



	printf("\n\nVALUE RANGES FOR INTEGER TYPES\n");


  /* char */
	c = 0;
	printf("\ncomputed UCHAR_MIN =          %11u == %11u = known UCHAR_MIN\n", c, 0);
	c = ~c;
	printf("computed UCHAR_MAX =          %11u == %11u = <limits.h> UCHAR_MAX\n", c, UCHAR_MAX);
	c >>= 1;
	printf("computed SCHAR_MAX =          %11d == %11d = <limits.h> SCHAR_MAX\n", c, SCHAR_MAX);
	c = ~c;
	printf("computed SCHAR_MIN =          %11d == %11d = <limits.h> SCHAR_MIN\n", -c, SCHAR_MIN);

  /* int */
	i = 0;
	printf("\ncomputed UINT_MIN  =          %11u == %11u = known UINT_MIN\n", i, 0);
	i = ~i;
	printf("computed UINT_MAX  =          %11u == %11u = <limits.h> UINT_MAX\n", i, UINT_MAX);
	i >>= 1;
	printf("computed INT_MAX   =          %11d == %11d = <limits.h> INT_MAX\n", i, INT_MAX);
	i = ~i;
	printf("computed INT_MIN   =          %11d == %11d = <limits.h> INT_MIN\n", -i, INT_MIN);

  /* short */
	s = 0;
	printf("\ncomputed USHRT_MIN =          %11u == %11u = known USHRT_MIN\n", s, 0);
	s = ~s;
	printf("computed USHRT_MAX =          %11u == %11u = <limits.h> USHRT_MAX\n", s, USHRT_MAX);
	s >>= 1;
	printf("computed SHRT_MAX  =          %11d == %11d = <limits.h> SHRT_MAX\n", s, SHRT_MAX);
	s = ~s;
	printf("computed SHRT_MIN  =          %11d == %11d = <limits.h> SHRT_MIN\n", s, SHRT_MIN);

  /* long */
	l = 0;
	printf("\ncomputed ULONG_MIN =          %11u == %11u = known ULONG_MIN\n", l, 0);
	l = ~l;
	printf("computed ULONG_MAX =          %11u == %11u = <limits.h> ULONG_MAX\n", l, ULONG_MAX);
	l >>= 1;
	printf("computed LONG_MAX  =  %11ld == %11ld = <limits.h> LONG_MAX\n", l, LONG_MAX);
	l = ~l;
	printf("computed LONG_MIN  = %11ld == %11ld = <limits.h> LONG_MIN\n", -l, LONG_MIN);





    // 	, %11u\n]",0,c*2+1);
    // }
    // printf("UCHAR_MAX:                     %11u\n",UCHAR_MAX);
    // printf("signed char:   %11d,           %11d\n",-c-1,c);
    // printf("SCHAR_MIN:     %11d, SCHAR_MAX %11d\n",SCHAR_MIN,SCHAR_MAX);
    // putchar('\n');

    // /* short */
    // s = ~0;
    // s >>= 1;
    // printf("signed short:   %6d,           %6d\n",-s-1,s);
    // printf("SHRT_MIN:       %6d, SHRT_MAX: %6d\n",SHRT_MIN,SHRT_MAX);
    // printf("unsigned short: %6u,           %6u\n",0,s*2+1);
    // printf("USHRT_MAX:                        %6u\n",USHRT_MAX);
    // putchar('\n');

    // /* int */
    // i = ~0;
    // i >>= 1;
    // printf("signed int:    %11d,          %11d\n",-i-1,i);
    // printf("INT_MIN:       %11d, INT_MIN: %11d\n",INT_MIN, INT_MAX);
    // printf("unsigned int:  %11u,          %11u\n",0,i*2+1);
    // printf("UINT_MAX:                            %11u\n",UINT_MAX);
    // putchar('\n');

    // /* long */
    // l = ~0;
    // l >>= 1;
    // printf("signed long:   %11ld,           %11ld\n",-l-1,l);
    // printf("LONG_MIN:      %11ld, LONG_MAX: %11ld\n",LONG_MIN, LONG_MAX);
    // printf("unsigned long: %11lu,           %11lu\n",0l,l*2+1);
    // printf("ULONG_MAX:                            %11lu\n", ULONG_MAX);
    // putchar('\n');


    // /* long long */
    // ll = ~0;
    // ll >>= 1;
    // printf("signed long long:   %20lld,            %20lld\n",-ll-1,ll);
    // printf("LLONG_MIN:          %20lld, LLONG_MAX: %20lld\n",LLONG_MIN, LLONG_MAX);
    // printf("unsigned long long: %20llu,            %20llu\n",0ll,ll*2+1);
    // printf("ULLONG_MAX:                                          %20llu\n", ULLONG_MAX);
    // return 0;

}