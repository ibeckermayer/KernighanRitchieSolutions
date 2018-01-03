#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>


void minscanf(char *fmt, ...);

int main()
{
  int day, year;
  char monthname[20];

  minscanf("%d %d", &day, &year);

  printf("%d %d\n", day, year);

}

void minscanf(char *fmt, ...)
{
  va_list ap; 			/* points to each unnamed arg in turn */
  char *p, *sval, c;

  va_start(ap, fmt);
  for (p = fmt; *p; p++) {
    if (*p != '%') {
      getchar();
      continue;
    }
    switch (*++p) {
    case 'd':
      scanf("%d", va_arg(ap, int *));
      break;
    case 'f':
      scanf("%f", va_arg(ap, float *));
      break;
    default:
      printf("improper formatting option: %c\n", *p);
      break;
    }
  }
  va_end(ap);
}
