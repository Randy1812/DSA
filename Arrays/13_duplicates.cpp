#include<iostream>

using namespace std;

struct Array
{
 int A[20];
 int size;
 int length;
};

void Display(Array arr)
{
 int i;
 cout<<"The elements are : \n";
 for(i=0;i<arr.length;i++)
    {
     cout<<arr.A[i]<<" ";
    }
}

void find_duplicates(Array &ar)
{
 int lastdup = 0;
 for(int i=0;i<ar.length-1;i++)
    {
     if(ar.A[i] == ar.A[i+1] && ar.A[i] != lastdup)
       {
        cout<<"The duplicated element is : "<<ar.A[i]<<"\n";
        lastdup = ar.A[i];
       }
    }
}

void count_duplicates(Array &ar)
{
 int i,j,ct=0;
 for(i=0;i<ar.length-1;i++)
    {
     if(ar.A[i] == ar.A[i+1])
       {
        j=i+1;
        while(ar.A[i]==ar.A[j])
             {
              j++;
             }
        cout<<"The element "<<ar.A[i]<<" appears "<<j-i<<" times.\n";
        ct+=j-i;
        i=j-1;
       }
    }
 cout<<"\n\nThere are "<<ct<<" duplicated elements.";
}

void duplicates_hash_all(Array &ar)
{
 int max = ar.A[0];
 int min = ar.A[0];
 for(int i=0;i<ar.length;i++)
     {
      if(ar.A[i]>max)
         max = ar.A[i];
      if(ar.A[i]<min)
         min = ar.A[i];
     }
 int *arr = new int[max];
 for(int i=0;i<max;i++)
     arr[i] = 0;
 for(int i=0;i<ar.length;i++)
    arr[ar.A[i]] += 1;
 for(int i=0;i<max;i++)
    {
     if(arr[i] > 1 && i > min)
       {
        cout<<"The duplicated element is "<<i<<" and it occurs "<< arr[i] <<" times.\n";
       }
    }
}

int main()
{
  Array arr1 = {{3,6,8,8,10,12,15,15,15,20},20,10};
  find_duplicates(arr1);
  cout<<"\n\n";
  count_duplicates(arr1);
  cout<<"\n\n";
  duplicates_hash_all(arr1);
}

