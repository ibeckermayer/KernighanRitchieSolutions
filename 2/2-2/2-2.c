#include <stdio.h>

int main() 
{
	int c, i, lim;
	lim = 1000;
	char s[lim];
	for(i=0; i<lim-1; ++i)
		if((c=getchar())!='\n')
			if(c!=EOF)
				s[i] = c;
	s[++i] = '\0';
	printf("%s\n", s);
}
