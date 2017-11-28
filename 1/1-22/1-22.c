#include <stdio.h>
#define MAXLENGTH 1000
#define CUTOFFLENGTH 10
int getline2(char [],int);
void copy(char [],char []);
void foldline(char line[], int length);
int findend(char seg[]);
int main()
{
  int len = 0;
  char line[MAXLENGTH];
    while((len=getline2(line,MAXLENGTH))>0){
      foldline(line, len);
    }
  return 0;
}

int getline2(char line[],int limit)
{
  int i,c;
  for(i=0;i<limit-1&&(((c=getchar())!=EOF)&&(c!='\n'));i++){
    line[i]=c;
  }
  if(i==(limit-1)){
    while((c=getchar())!='\n'){
      ++i;
    }
  }
  if(c=='\n'){        
    line[i]=c;
    ++i;
  }
  /* line[i]='\0'; */
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
void foldline(char line[], int length)
{
  int segstart, segend, i, current;
  char seg[CUTOFFLENGTH];
  segstart = 0;
  segend = 0;
  while (segstart < length) {
    printf("\nBEGIN:\n\nsegstart = %d\nlength = %d\n", segstart, length);
    /* reset seg */
    for (i = 0; i <= CUTOFFLENGTH; ++i)
      seg[i]='.';
    printf("seg_reset = %s\n", seg);
    /* get the segment */
    for (i = segstart; i <= segstart+CUTOFFLENGTH; ++i){
      if ((current=line[i]) != '\0')
	seg[i-segstart] = current;
    }
    /* find the end of the segment */
    segend = findend(seg);
    printf("seg = %s\n", seg);
    printf("segend = %d\n", segend);
    /* print the segment */
    for (i = segstart; i <=segstart+segend; ++i)
      putchar(line[i]);
    if (line[segstart+segend] != '\n')
      putchar('\n');

    /* repeat */
    segstart = segstart + segend + 1;
    printf("segstart at end = %d\n", segstart);
  }
}

/* prints a segment and returns the index of the last character printed. Makes sure that printing ends at the end of a word */
int findend(char seg[])
{
  int i;
  for (i=CUTOFFLENGTH-1; i>=0; i=i-1){
    if (seg[i] == '\n' || seg[i] == ' ' || seg[i] == '\t' || seg[i] == '\0')
      return i;
  }
}
