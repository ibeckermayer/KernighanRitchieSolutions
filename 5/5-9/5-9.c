#include <stdio.h>

void month_day(int year, int yearday, int *pmonth, int *pda);
int day_of_year(int year, int month, int day);

int main() {
  int *pmonth;
  int *pda;

  int doy = day_of_year(2017, 12, 16);
  month_day(2017, doy, pmonth, pda);

  printf("12/16 is the %d day of the year 2017,\n the %d day of the year 2017 is %d/%d", doy, doy, *pmonth, *pda);
}

static char *daytab[] = {
{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, 
{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day)
{
  int i, leap;

  leap = year%4 ==0 && year%100 !=0 || year %400 == 0;

  if (year < 0 || month <0 || month > 12 || (day < 0 || day > *(*(daytab+leap)+(month-1)))) {
      printf("date invalid\n");
      return -1;
    }

  for (i = 1; i < month; i++)
    day += *(*(daytab+leap)+i);
  return day;
}

void month_day(int year, int yearday, int *pmonth, int *pda)
{
  int i, leap;

  leap = year%4 ==0 && year%100 !=0 || year %400 == 0;
  if (year < 0 || yearday < 0 || (leap ? yearday > 366 : yearday > 365)) {
      printf("date invalid\n");
      return;
  }

  for (i = 1; yearday > *(*(daytab+leap)+i); i++)
    yearday -=  *(*(daytab+leap)+i);
  *pmonth = i;
  *pda = yearday;
}
