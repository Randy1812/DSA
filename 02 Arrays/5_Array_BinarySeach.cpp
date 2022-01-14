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

void swap(int *x, int *y)
{
 int temp = *x;
 *x = *y;
 *y = temp;
}

int LinearSearch(Array &arr, int x)
{
 for(int i=0;i<arr.length;i++)
    {
     if(x == arr.A[i])
       {
        swap(&arr.A[i],&arr.A[i-1]);
        return i;
       }
    }
 return -1;
}

int BinarySearch(Array &arr, int x)
{
 int l=0,h=arr.length,m;
 while(l<=h)
      {
       m = (l+h)/2;
       if(arr.A[m] == x)
         return m;
       else
       if(arr.A[m] > x)
           h = m-1;
       else
          l = m+1;
      }
 return -1;
}

int main()
{
  Array arr = {{2,3,4,5,6}, 20, 5};
//  Append(arr,7);
//  Insert(arr,0,8);
  int el = 5;
//  cout<<"The element "<<el<<" is found at Position : "<<LinearSearch(arr,el)<<endl;
  cout<<"The element "<<el<<" is found at Position : "<<BinarySearch(arr,el)<<endl;
  Display(arr);
}

