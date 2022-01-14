#include<stdio.h>

using namespace std;

void fun(int n)
{
 if(n>0)
   {
    fun(n-1);
    printf("%d ",n);
   }
}

int main()
{
 fun(3);
}

