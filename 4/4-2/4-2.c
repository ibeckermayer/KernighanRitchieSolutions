#include <ctype.h>
#include <stdio.h>
double atof(char s[]);

int main()
{
  printf("%.8f\n", atof("123.45e-6"));
}

double atof(char s[])
{
  double val, val2, power, temp_return;
  int i, sign, sign2;

  for(i = 0; isspace(s[i]); i++)
    ;
  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')
    i++;
  for (val = 0.0; isdigit(s[i]); i++)
    val = 10.0 * val + (s[i] - '0');
  if (s[i] == '.')
    i++;
  for (power = 1.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
    power *= 10;
  }
  temp_return = sign * val / power;
  if (s[i] == 'e' || s[i] == 'E')
    i++;
  sign2 = (s[i] == '-') ? 0 : 1;
  if (s[i] == '-' || s[i] == '+')
    i++;
  for (val2 = 0.0; isdigit(s[i]); i++)
    val2 = 10.0 * val2 + (s[i] - '0');
  for (power = 1.0, i = 0; i < val2; i++)
    power*=10;
  if (sign2)
    power = 1.0/power;
  return temp_return / power;
}
