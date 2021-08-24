#include<stdio.h>

using namespace std;

double taylor_iter(int x, int n)
{
 double s=1;
 int i;
 double num=1;
 double den=1;
 for(i=1;i<n;i++)
    {
     num*=x;
     den*=i;
     s+=num/den;
    }
 return s;
}

int main()
{
 printf("%f ",taylor_iter(1,10));
}
