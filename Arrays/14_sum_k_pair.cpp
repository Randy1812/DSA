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

void sum_k_pair(Array ar, int sum)
{
  int i,j;
  for(i=0;i<ar.length-1;i++)
     {
       for(j=i+1;j<ar.length;j++)
          {
           if(ar.A[i]+ar.A[j] == sum)
             {
              cout<<"("<<ar.A[i]<<","<<ar.A[j]<<")\n";
             }
          }
     }
}

void sum_k_pair_hash(Array ar, int sum)
{
  int i;
  int mx = ar.A[0],req;
  for(i=0;i<ar.length;i++)
     {
      if(ar.A[i] > mx)
        {
         mx = ar.A[i];
        }
     }
 int *arr = new int[mx+1];
 for(i=0;i<ar.length;i++)
    {
     req = sum - ar.A[i];
     if(arr[req] != 0  && req >= 0)
       {
        cout<<"("<<ar.A[i]<<","<<req<<")\n";
       }
     arr[ar.A[i]]++;
    }
}

void sum_k_pair_sorted(Array ar, int sum)
{
 int i = 0;
 int j = ar.length-1;
 while(i<j)
      {
       if(ar.A[i] + ar.A[j] > sum)
         {
          j--;
         }
       else if(ar.A[i] + ar.A[j] == sum)
         {
          cout<<"("<<ar.A[i]<<","<<ar.A[j]<<")\n";
          i++;
          j--;
         }
       else
         {
          i++;
         }
      }
}

int main()
{
  Array arr1 = {{6,3,8,10,16,7,5,2,9,14},20,10};
  sum_k_pair(arr1,12);
  cout<<endl<<endl;
  sum_k_pair_hash(arr1,12);
  cout<<endl<<endl;
  Array arr2 = {{1,3,4,5,6,8,9,10,12,14},20,10};
  sum_k_pair_sorted(arr2,10);
}


