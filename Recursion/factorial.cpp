#include<stdio.h>

using namespace std;

int fact(int n)
{
 if(n<0)
   {
    printf("invalid Input");
    return -1;
   }
 if(n==0)
   {
    return 1;
   }
 return n*fact(n-1);
}

int main()
{
 int n=5;
 printf("%d ",fact(n));
}
