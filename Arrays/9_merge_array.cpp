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

void merge_array(Array &ar1, Array &ar2, Array &ar3)
{
 int i=0;
 int j=0;
 int k=0;
 while(i<ar1.length && j<ar2.length)
      {
       if(ar1.A[i] < ar2.A[j])
         {
          ar3.A[k++] = ar1.A[i++];
         }
       else if(ar1.A[i] == ar2.A[j])
         {
          ar3.A[k++] = ar1.A[i++];
          ar3.A[k++] = ar2.A[j++];
         }
       else
         {
          ar3.A[k++] = ar2.A[j++];
         }
      }
 while(i<ar1.length)
      {
       ar3.A[k++] = ar1.A[i++];
      }
 while(j<ar2.length)
      {
       ar3.A[k++] = ar2.A[j++];
      }
 ar3.size=ar1.size+ar2.size;
 ar3.length = k;
}

int main()
{
  Array arr1 = {{3,8,16,20,25},20,5};
  Array arr2 = {{4,10,12,22,23},20,5};
  Array arr3;
  merge_array(arr1,arr2,arr3);
  Display(arr3);
}
