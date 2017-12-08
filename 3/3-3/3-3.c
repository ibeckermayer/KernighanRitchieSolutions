#include <stdio.h>
#define MAXLEN 1000

void expand(char s1[], char s2[]);

int main()
{
  char s1[MAXLEN] = "a-z";
  char s2[MAXLEN] = "a-b-c";
  char s3[MAXLEN] = "a-z0-9";
  char s4[MAXLEN] = "-a-z";
  char s9[MAXLEN] = "a-z-";

  char s5[MAXLEN];  
  char s6[MAXLEN];
  char s7[MAXLEN];
  char s8[MAXLEN];
  char s10[MAXLEN];


  expand(s1,s5);
  printf("%s becomes %s\n", s1, s5);
  expand(s2,s6);
  printf("%s becomes %s\n", s2, s6);
  expand(s3,s7);
  printf("%s becomes %s\n", s3, s7);
  expand(s4,s8);
  printf("%s becomes %s\n", s4, s8);
  expand(s9,s10);
  printf("%s becomes %s\n", s9, s10);
}

void expand(char s1[], char s2[])
{
  int i, j, c;
  i=j=0;
  while ((c = s1[i++])!='\0') {
    if ((c>='0' && c<='9') || (c>='a' && c<='z')) {
      if (s1[i]=='-') {
	int cc = s1[++i];
	while (c<=cc) 
	  s2[j++]=c++;
      }
    }
  }
  s2[j++]='\0';
}
