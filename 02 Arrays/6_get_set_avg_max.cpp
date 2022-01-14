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

int Get(Array &ar, int pos)
{
 if(pos>=0 && pos<ar.length)
    return ar.A[pos];
  return -1;
}

void Set(Array &ar, int pos, int x)
{
 if(pos>=0 && pos<ar.length)
    ar.A[pos] = x;
}

int Max(Array &ar)
{
 int max = ar.A[0];
 for(int i=1;i<ar.length;i++)
    {
     if(max<ar.A[i])
        max = ar.A[i];
    }
 return max;
}

int Min(Array &ar)
{
 int min = ar.A[0];
 for(int i=1;i<ar.length;i++)
    {
     if(min>ar.A[i])
        min = ar.A[i];
    }
 return min;
}

int Sum(Array &ar)
{
 int s=0;
 int i;
 for(i=0;i<ar.length;i++)
    {
     s+=ar.A[i];
    }
 return s;
}

float Avg(Array &ar)
{
 return (float)Sum(ar)/ar.length;
}

int main()
{
  Array arr = {{2,3,4,5,6},20,5};
  Set(arr,0,15);
  printf("%d\n\n",Max(arr));
  printf("%d\n\n",Min(arr));
  printf("%d\n\n",Sum(arr));
  printf("%f\n\n",Avg(arr));
  Display(arr);
}

