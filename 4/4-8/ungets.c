#include <cstring.h>
void ungets(s[])
{
  size_t i = strlen(s);

  while (i > 0)
    ungetch(s[--i]);
}
