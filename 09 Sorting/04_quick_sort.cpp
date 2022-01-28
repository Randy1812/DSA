
#include<iostream>

using namespace std;

int partition(int ar[], int l, int h)
{
 int pivot=ar[l];
 int i=l,j=h;
 do
   {
    do{i++;}while(ar[i]<=pivot);
    do{j--;}while(ar[j]>pivot);
    if(i<j)
      {
       swap(ar[i],ar[j]);
      }
   }while(i<j);
 swap(ar[l],ar[j]);
 return j;
}

void quick_sort(int ar[], int l ,int h)
{
 int j;
 if(l<h)
   {
   j=partition(ar,l,h);
   quick_sort(ar,l,j);
   quick_sort(ar,j+1,h);
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
 int ar[]={9,8,7,6,5,4,3,2,1,0,INT_MAX};
 quick_sort(ar,0,10);
 disp(ar,10);
}


