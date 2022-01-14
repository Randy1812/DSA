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

void insert_sorted(Array &ar, int x)
{
 int i=ar.length-1;
 ar.length++;
 while(ar.A[i]>=x && i>=0)
      {
       ar.A[i+1] = ar.A[i];
       i--;
      }
 ar.A[i+1] = x;
}

bool check_sorted(Array &ar)
{
 for(int i=0;i<ar.length-1;i++)
    {
     if(ar.A[i]>ar.A[i+1])
        return false;
    }
 return true;
}

void arrange_neg(Array &ar)
{
 int i=0,j=ar.length-1;
 while(i<j)
      {
       while(ar.A[i]<0)
             i++;
       while(ar.A[j]>=0)
             j--;
       swap(ar.A[i],ar.A[j]);
      }
}


int main()
{
//  Array arr = {{1,2,3,4,6,7},20,6};
  Array arr = {{-6,4,5,-21,78,34,-44},20,7};
  arrange_neg(arr);
  insert_sorted(arr,5);
  cout<<((check_sorted(arr))?"Sorted":"Not Sorted")<<"\n\n";
  Display(arr);
}


