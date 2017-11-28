#include <stdio.h>
#define MAXLENGTH 1000
int getline2(char [],int);
void copy(char [],char []);
void reverseline(char line[], char reverse[], int length);
int main()
{
  int len = 0;
  char line[MAXLENGTH];
  char reverse[MAXLENGTH];
    while((len=getline2(line,MAXLENGTH))>0){
      /* printf("%d\n",len);  */
      reverseline(line, reverse, len);
      printf("%s", reverse);
    }
  return 0;
}

int getline2(char line[],int limit)
{
  int i,c;
  for(i=0;i<limit-1&&(((c=getchar())!=EOF)&&(c!='\n'));i++)
    line[i]=c;
  if(i==(limit-1)){
    while((c=getchar())!='\n'){
      ++i;
    }
  }
  if(c=='\n'){        
    line[i]=c;
    ++i;
  }
  line[i]='\0';
  return i;
}

void copy(char to[],char from[])
{
  int i=0;
  while((to[i]=from[i])!='\0')
    ++i;
}

/* remove trailing tabs and blanks from line */
void reverseline(char line[], char reverse[], int length)
{
  int i;
  char current;
  for (i = length-2; i >= 0; i = i-1) {
    current = line[i];
    reverse[length-2-i] = current;
  }
  /* printf("%d",current); */
  reverse[length-1]='\n';
  reverse[length]='\0';
 
}

