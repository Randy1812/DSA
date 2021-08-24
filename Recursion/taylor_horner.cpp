#include<stdio.h>

using namespace std;

double taylor_horner(int x, int n)
{
  static double s=1;
  if(n==0)
    return s;
  s=1+x*s/n;
  return taylor_horner(x,n-1);
}

int main()
{
 printf("%f ", taylor_horner(2,10));
}

