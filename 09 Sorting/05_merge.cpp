#include<iostream>

using namespace std;

int merge_sort(int a[], int b[], int n, int m, int c[])
{
 int i=0,j=0,k=0;
 while(i<n && j<m)
      {
       if(a[i]<b[j])
         {
          c[k++]=a[i++];
         }
       else
         {
          c[k++]=b[j++];
         }
      }
 while(i<n)
      {
       c[k++]=a[i++];
      }
 while(j<m)
      {
       c[k++]=b[j++];
      }
 return k;
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
 int a[]={2,10,18,20,23};
 int b[]={4,9,19,25};
 int c[10];
 int k = merge_sort(a,b,5,4,c);
 disp(c,k);
}

