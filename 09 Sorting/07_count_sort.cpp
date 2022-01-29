#include<bits/stdc++.h>

using namespace std;

void count_sort(int a[], int n)
{
 int max=*max_element(a,a+n);
 int *c = new int[max+1]{0};
 for(int i=0;i<n;i++)
    {
     c[a[i]]++;
    }
 int i=0,j=0;
 while(i<max+1)
      {
       if(c[i]>0)
         {
          a[j++]=i;
          c[i]--;
         }
       else
         {
          i++;
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
 int ar[]={8,3,7,4,9,2,6,5};
 count_sort(ar,8);
 disp(ar,8);
}
