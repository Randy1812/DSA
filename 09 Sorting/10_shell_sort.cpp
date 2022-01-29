#include<iostream>

using namespace std;

void shell_sort(int ar[], int n)
{
 int gap,i,j,temp;
 for(gap=n/2;gap>=1;gap/=2)
    {
     for(i=gap;i<n;i++)
        {
         temp=ar[i];
         j=i-gap;
         while(j>0 && ar[j]>temp)
              {
               ar[j+gap]=ar[j];
               j-=gap;
              }
         ar[j+gap]=temp;
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
 shell_sort(ar,10);
 disp(ar,10);
}


