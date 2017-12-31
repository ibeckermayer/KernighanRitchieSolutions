#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define BUFSIZE 100
#define MAXLINES 1000

typedef struct tnode *Treeptr;
typedef struct tnode 
{
  char *word; 
  int lines[MAXLINES]; 		/* keeps track of which line numbers the word shows up on */
  int index;			/* keeps track of which index to add the next line number to */
  Treeptr left;
  Treeptr right;
} Treenode;

int getch(void);
void ungetch(int);
int getword(char *word, int lim);
int isvalidchar(char c);
int isskip(char c);
Treeptr talloc(void);
char *strdup2(char *);
void treeprint(Treeptr p);
void printlines(int *lines, int len);
Treeptr addtree(Treeptr p, char *w);

char buf[BUFSIZE];
int bufp = 0;
int current_line = 1;

int main() 
{
  Treeptr root;
  char word[BUFSIZE];

  root = NULL;
  while (getword(word, BUFSIZE) != EOF)
    if (isalpha(word[0]))
      root = addtree(root, word);
  treeprint(root);
  return 0;
}

void treeprint(Treeptr p)
{
  if (p != NULL) {
    treeprint(p->left);
    printf("%-16s", p->word);
    printlines(p->lines, p->index);
    treeprint(p->right);
  }
}

void printlines(int *lines, int len)
{
  int i;
  for (i = 0; i < len ; i++)
    printf("%4d", lines[i]);
  putchar('\n');
}

Treeptr addtree(Treeptr p, char *w)
{
  int cond;

  if (p == NULL) { 		/* a new word has arrived */
    p = talloc(); 		/* make a new node */
    p->word = strdup2(w);
    p->index = 0;
    p->lines[p->index++] = current_line;
    p->left = p->right = NULL;
  } else if ((cond = strcmp(w, p->word)) == 0) {
    p->lines[p->index++] = current_line; /* repeated word */
  }  else if (cond < 0)
    p->left = addtree(p->left, w);
  else
    p->right = addtree(p->right, w);
  return p;
}

Treeptr talloc(void)
{
  return (Treeptr) malloc(sizeof(Treenode));
}

char *strdup2(char *s)
{
  char *p;

  p = (char *) malloc(strlen(s)+1); /* +1 for '\0' */
  if (p != NULL)
    strcpy(p, s);
  return p;
}

int isvalidchar(char c)
{
  if (isalnum(c) || c == '_')
    return 1;
  else
    return 0;

}

int isskip(char c)
{

  if (c == '\n' || c == '\r')
    current_line++;

  if (isspace(c))
    return 1;

  switch(c) {
  case '#' :
  case '/' :
  case '*' :
  case '<' :
  case '>' :
  case '\'':
  case '\"':
  case ';' :
  case '}' :
  case '{' :
  case '(' :
  case ')' :
  case '=' :
  case ':' :
    return 1;
  default :
    return 0;
  }
}

int getword(char *word, int lim)
{
  char *w = word;
  int c;

  while (isskip(c = getch()))
    ;
  if (c != EOF)
    *w++ = c;
  if (!isalpha(c)) {
    *w = '\0';
    return c;
  }
  for ( ; --lim > 0; w++)
    if (!isvalidchar(*w = getch())) {
      ungetch(*w);
      break;
    }
  *w = '\0';
  return word[0];
}

int getch(void)
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}
