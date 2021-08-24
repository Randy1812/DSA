#include<stdio.h>

using namespace std;

int sum(int n)
{
 if(n==0)
    return 0;
 return sum(n-1) + n;
}

int main()
{
 int n=5;
// Using Recursion
 printf("%d ",sum(n));
// Using Formula
 printf("%d",(n*(n+1)/2));
}
