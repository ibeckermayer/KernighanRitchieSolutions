#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calc.h"
#define MAXOP 100
int main(int argc, char *argv[])
{
  int type;
  double op2;
  char s[MAXOP];

  while ((type = getop(s, argc, argv)) != EOF) {
    switch (type) {
    case NUMBER:
      push(atof(s));
      break;
    case '+':
      push(pop() + pop());
      break;
    case '*':
      push(pop() * pop());
      break;
    case '-':
      op2 = pop();
      push(pop() - op2);
      break;
    case '/':
      op2 = pop();
      if (op2 != 0.0)
	push(pop() / op2);
      else
	printf("error: zero divisor\n");
      break;
    case '%':
      op2 = pop();
      if (op2 != 0.0)
	push((int)pop() % (int)op2);
      else
	printf("error: zero divisor\n");
      break;
    case 128:
      push(sin(pop()));
      break;
    case 129:
      push(cos(pop()));
      break;
    case 130:
      push(exp(pop()));
      break;
    case 131:
      op2 = pop();
      push(pow(pop(), op2));
      break;
    case '\n':
      printf("\t%.8g\n", pop());
      break;
    default:
      printf("error: unknown command %s\n", s);
      break;
    }
  }
  printf("\t%.8g\n", pop());
  return 0;
}
