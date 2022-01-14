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

void reverse(Array &ar)
{
 int tmp;
 for(int i=0;i<ar.length/2;i++)
    {
     tmp = ar.A[i];
     ar.A[i] = ar.A[ar.length-i-1];
     ar.A[ar.length-i-1] = tmp;
    }
}

int main()
{
  Array arr = {{2,3,4,5,6,7},20,6};
  reverse(arr);
  Display(arr);
}

