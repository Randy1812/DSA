#include<bits/stdc++.h>>

using namespace std;

void insert(vector<int> &ar, int num)
{
 int i=ar.size();
 ar.push_back(num);
 while(i>=0 && num>ar[i%2==0?(i/2)-1:i/2])
      {
       ar[i]=ar[i%2==0?(i/2)-1:i/2];
       i=i%2==0?(i/2)-1:i/2;
      }
 ar[i]=num;
}

vector<int> create_heap(int ar[], int s)
{
 vector<int> heap;
 heap.push_back(ar[0]);
 for(int i=1;i<s;i++)
    {
     insert(heap,ar[i]);
    }
 return heap;
}

void del(vector<int> &ar, int &s)
{
 int n=s-1;
 int x,i,j;
 x=ar[0];
 ar[0]=ar[n];
 i=0;
 j=2*i+1;
 while(j<n-1)
      {
       if(ar[j+1]>ar[j])
         {
          j+=1;
         }
       if(ar[i]<ar[j])
         {
          swap(ar[i],ar[j]);
          i=j;
          j=2*i+1;
         }
       else
         {
          break;
         }
      }
 ar[n]=x;
 s--;
}

void disp(vector<int> heap)
{
 cout<<"The heap is as follows : ";
  for(auto i:heap)
    {
     cout<<i<<" ";
    }
 cout<<"\n";
}

void heap_sort(vector<int> &ar, int &s)
{
 while(s>=1)
      {
       del(ar,s);
      }
 disp(ar);
}

void heapify(vector<int> &ar, int &n)
{
 for(int i=(n/2)-1;i>=0;i--)
    {
     int j=(2*i)+1;
     while(j<n-1)
          {
           if(ar[j]<ar[j+1])
             {
              j=j+1;
             }
           if(ar[i]<ar[j])
             {
              swap(ar[j],ar[i]);
              i=j;
              j=2*i+1;
             }
           else
             {
              break;
             }
          }
    }
 disp(ar);
}

int main()
{
 int b[] = {10, 20, 30, 25, 5, 40, 35};
// vector<int> heap=create_heap(b,7);
// disp(heap);
// int s=7;
// heap_sort(heap,s);



 vector<int> heap={10,20,30,25,5,40,35};
 disp(heap);
 int s=7;
 heapify(heap,s);
}
