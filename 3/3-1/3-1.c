#include <stdio.h>
#include <time.h>
#define ARRAYSIZE 10
int binsearch(int x, int v[], int n);
int binsearch2(int x, int v[], int n);

int main()
{
  int n = ARRAYSIZE;
  int x = 5;
  int v[ARRAYSIZE] ={0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  clock_t start1, end1, start2, end2;
  double cpu_time_used1, cpu_time_used2;

  start1 = clock();
  binsearch(x,v,n);
  end1 = clock();
  cpu_time_used1 = ((double) (end1-start1)) / CLOCKS_PER_SEC;

  start2 = clock();
  binsearch2(x,v,n);
  end2 = clock();
  cpu_time_used2 = ((double) (end2-start2)) / CLOCKS_PER_SEC;

  printf("original function time taken: ~%f\n", cpu_time_used1);
  printf("new function time taken: ~%f\n", cpu_time_used2);
}

int binsearch(int x, int v[], int n)
{
  int low, high, mid;
  low = 0;
  high = n-1;
  while (low<=high) {
    mid = (low+high)/2;
    if (x < v[mid])
      high = mid-1;
    else if (x > v[mid])
      low = mid+1;
    else
      return mid;
  }
  return -1;
}

int binsearch2(int x, int v[], int n)
{
  int low, high, mid;
  low = 0;
  high = n-1;
  while (low<high) {
    mid = (low+high)/2;
    if (x < v[mid])
      high = mid-1;
    else
      low = mid+1;
  }
  if (x==v[mid])
    return mid;
  else
    return -1;
}
