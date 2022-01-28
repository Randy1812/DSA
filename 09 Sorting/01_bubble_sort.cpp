#include<iostream>

using namespace std;

void bub_sort(int ar[], int n)
{
 int i,j;
 for(i=0;i<n;i++)
    {
     for(j=0;j<n-i-1;j++)
        {
         if(ar[j]>ar[j+1])
           {
            swap(ar[j],ar[j+1]);
           }
        }
    }
}

void disp(int ar[], int n)
{
 for(int i=0;i<n;i++)
    {
     cout<<ar[i]<<" ";
    }
 cout<<"\n";
}

int main()
{
 int ar[]={9,8,7,6,5,4,3,2,1,0};
 bub_sort(ar,10);
 disp(ar,10);
}
