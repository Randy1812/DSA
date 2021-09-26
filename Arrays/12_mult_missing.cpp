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

void find_missing(Array &ar)
{
// For Sorted Arrays
 int l = ar.A[0];
 int h = ar.A[ar.length-1];
 int diff = l;
 for(int i=0;i<ar.length;i++)
    {
     if(ar.A[i]-i != diff)
       {
        while(diff < ar.A[i]-i)
             {
              cout<<"The missing element is : "<<(i + diff)<<"\n";
              diff++;
             }
       }
    }
}

void find_missing_v2(Array &ar)
{
// For unsorted arrays done using hashing
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
     if(arr[i] == 0 && i > min)
       {
        cout<<"The missing element is : "<<i<<"\n";
       }
    }
}


int main()
{
  Array arr1 = {{6,7,8,9,11,12,15,16,17,18,19},20,11};
  find_missing_v2(arr1);
}

