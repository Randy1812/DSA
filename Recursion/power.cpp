#include<stdio.h>

using namespace std;

double power_naive(int m, int n)
{
 if(n==0)
   {
    return 1;
   }
 return m*power_naive(m,n-1);
}

double power(int m, int n)
{
 if(n==0)
   {
    return 1;
   }
 if(n%2==0)
   {
    return power(m*m,n/2);
   }
 else
   {
    return m*power(m*m,(n-1)/2);
   }
}

int main()
{
 printf("%.2f \n\n",power_naive(5,5));
 printf("%.2f \n\n",power_naive(5,4));
 printf("%.2f \n\n",power(5,5));
 printf("%.2f \n\n",power(5,4));
}
