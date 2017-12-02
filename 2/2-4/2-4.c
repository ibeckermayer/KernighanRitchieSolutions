#include <stdio.h>
void squeeze (char s[], char ss[]);
int is_in(char c, char ss[]);

int main()
{
	char s[100]  = "0123456";
	char ss[100] = "0246";
	putchar('\n');
	printf("s = %s\n", s);
	printf("ss = %s\n\n", ss);
	squeeze(s, ss);
	printf("squeezed ss from s: %s\n\n", s);
}

// squeeze all the chars in ss out of s
void squeeze (char s[], char ss[])
{
	int i, j, k;

	for (i = j = 0; s[i] != '\0'; i++)
		if (!is_in(s[i], ss))
			s[j++] = s[i];
	s[j] = '\0';
}

int is_in(char c, char ss[]) 
{
	int i;

	for (i = 0; ss[i] != '\0'; i++)
		if (ss[i]==c)
			return 1;
	return 0;
}