#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 100

void filecopy(FILE *, FILE *);
int getline2(char *line, int max, FILE *fp);

int main(int argc, char *argv[])
{
  FILE *fp1, *fp2;		/* file pointers for both files */
  char *prog = argv[0]; 	/* program name for errors */
  char line1[MAXLINE], line2[MAXLINE]; /* placeholders for each line as they are read */
  int cur_line = 0;

  if (argc != 3) { 		/* improper number of args */
    fprintf(stderr, "program call must contain two arguments\n");
    exit(1);
  } 
  else {
    fp1 = fopen(*++argv, "r");
    fp2 = fopen(*(argv+1), "r");
    if (fp1 == NULL || fp2 == NULL) {
      fprintf(stderr, "%s: can't open either %s or %s\n", prog, *argv, *(argv+1));
      exit(2);
    } else {
      while(1) {
	int li1, li2;
	li1 = getline2(line1, MAXLINE, fp1);
	li2 = getline2(line2, MAXLINE, fp2);
	cur_line++;
	if (li1 == 0 && li2 == 0) {
	    printf("Files are the same\n");
	    return 0;
	} else if ((li1 == 0) != (li2 == 0)) { /* one of the files has ended */
	  printf("Files first differ at line %d\n", cur_line);
	  return 0;
	} else if (strcmp(line1, line2) != 0) {
	  printf("Files first differ at line %d\n", cur_line);
	  return 0;
	} else {
	  continue;
	}
      }
    }
  }
}
/* 	while (getline2(line1, MAXLINE, fp1) && getline2(line2, MAXLINE, fp2)) { */
/* 	  cur_line++; */
/* 	  if (strcmp(line1, line2)) { */
/* 	    printf("Files first differ at line %d\n", cur_line); */
/* 	    return 0; */
/* 	  } */
/* 	} */
/* 	if (strcmp(line1, line2) == 0) */
/* 	  printf("Files are the same\n"); */
/* 	else */
/* 	  printf("Files first differ at lineeee %d\n", cur_line); */
/* 	return 0; */
/*       } */

/* filecopy: copy file ifp to file ofp */
void filecopy(FILE *ifp, FILE *ofp)
{
  int c;

  while ((c = getc(ifp)) != EOF)
    putc(c, ofp);
}

int getline2(char *line, int max, FILE *fp)
{
  if (fgets(line, max, fp) == NULL)
    return 0;
  else
    return strlen(line);
}
