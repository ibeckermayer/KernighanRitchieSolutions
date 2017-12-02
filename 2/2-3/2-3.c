#include <stdio.h> 
void print_hex_to_dec(char c);

int main()
{
	int c, d;
	while((c=getchar()) != EOF)
	{
		if (c=='0')
		{
			if ((d=getchar())!='x'&&d!='X')
			{
				print_hex_to_dec(c);
				print_hex_to_dec(d);
			}
		}	
		else if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f'))
		{
			print_hex_to_dec(c);
		}
	}
}

void print_hex_to_dec(char c) 
{
	if (c >= '0' && c <= '9')
	{
		printf("%d\n", c-'0');
	}
	else if (c >= 'A' && c <= 'F')
	{
		printf("%d\n", c-'A'+11);
	}
	else if (c >= 'a' && c <= 'f')
	{
		printf("%d\n", c-'a'+11);
	}
	else
	{
		printf("All characters must be 0-9, A-F, or A-F, you put: %c", c);
	}
}