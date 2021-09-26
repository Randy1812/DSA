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
 int l = ar.A[0];
 int h = ar.A[ar.length-1];
 int diff = l;
 for(int i=0;i<ar.length;i++)
    {
     if(ar.A[i]-i != diff)
       {
        cout<<"The missing element is : "<<(i+diff);
        break;
       }
    }
}


int main()
{
  Array arr1 = {{1,2,3,4,5,6,7,8,9,11,12,13,14,15},20,14};
  find_missing(arr1);
}
