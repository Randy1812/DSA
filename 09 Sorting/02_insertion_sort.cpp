#include<iostream>

using namespace std;

void insert_sort(int ar[], int n)
{
 int i,j,tmp;
 for(i=1;i<n;i++)
    {
     j=i-1;
     tmp=ar[i];
     while(ar[j]>tmp&&j>=0)
          {
           ar[j+1]=ar[j];
           j--;
          }
     ar[j+1]=tmp;
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
 insert_sort(ar,10);
 disp(ar,10);
}

