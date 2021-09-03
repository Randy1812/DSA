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

void Append(Array &arr, int x)
{
 if(arr.length<arr.size)
   {
    arr.A[arr.length++] = x;
   }
}

void Insert(Array &arr, int index, int x)
{
 int i;
 if(index >= 0 && index <= arr.length)
   {
    for(i=arr.length;i>index;i--)
       {
        arr.A[i] = arr.A[i-1];
       }
    arr.A[index] = x;
    arr.length++;
   }
}

void Delete(Array &arr, int index)
{
 if(index >= 0 && index <= arr.length)
   {
    for(int i=index;i<arr.length-1;i++)
       {
        arr.A[i] = arr.A[i+1];
       }
   }
   arr.length--;
}

int main()
{
  Array arr = {{2,3,4,5,6}, 20, 5};
//  Append(arr,7);
//  Insert(arr,0,8);
  Delete(arr,2);
  Display(arr);
}

