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

void max_min_single_scan(Array ar)
{
 int min, max;
 min = ar.A[0];
 max = ar.A[0];
 for(int i=1;i<ar.length;i++)
    {
     if(ar.A[i]<min)
       {
        min = ar.A[i];
       }
     else if(ar.A[i]>max)
       {
        max = ar.A[i];
       }
    }
 cout<<"Max = "<<max<<"\nMin = "<<min;
}

int main()
{
  Array arr1 = {{5,8,3,9,6,2,10,7,-1,4},20,10};
  max_min_single_scan(arr1);
}



