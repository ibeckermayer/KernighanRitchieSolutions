#include <stdio.h>
void escape(char s[], char t[]);

int main()
{
  char s[1000] = "\t\n\t\n\t";
  char t[1000];
  printf("\noriginal string was %s\n", s);
  escape(s, t);
  printf("which converted to escape characters looks like %s\n\n", t);
  
}

/* copy s to t, converting all escape characters to a string denoting that character */
void escape(char s[], char t[])
{
  int i, j;
  i = j= 0;
  char c;
  while ((c = s[i++]) != '\0') 
    {
      switch (c) {
      case '\n': 
	t[j++] = '\\';
	t[j++] = 'n';
	break;
      case '\t':
	t[j++] = '\\';
        t[j++] = 't';
        break;
      default:
	t[j++] = c;
      }
    }
    
}

/* elected not to do second part, it's trivial (just somewhat time consuming) */
