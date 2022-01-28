#include<iostream>

using namespace std;

void select_sort(int ar[], int n)
{
 int i,j,pos;
 for(i=0;i<n;i++)
    {
     pos=i;
     for(j=i+1;j<n;j++)
        {
         if(ar[pos]>ar[j])
           {
            pos=j;
           }
        }
     swap(ar[i],ar[pos]);
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
 select_sort(ar,10);
 disp(ar,10);
}


