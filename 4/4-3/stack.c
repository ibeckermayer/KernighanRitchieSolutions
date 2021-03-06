#include <stdio.h>
#include "calc.h"
#define MAXVAL 100
int sp = 0;
double val[MAXVAL];

void push(double f)
{
  if (sp < MAXVAL)
    val[sp++] = f;
  else
    printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
  if (sp > 0)
    return val[--sp];
  else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

void print_top(void)
{
  printf("top of stack is %f\n", val[sp]);
}

double duplicate_top(void)
{
  return val[sp];
}

void swap_top_two(void)
{
  double temp1 = val[sp];
  double temp2 = val[sp-1];
  val[sp] = temp2;
  val [sp-1] = temp2;
}

void clear_stack(void)
{
  sp = 0;
}
