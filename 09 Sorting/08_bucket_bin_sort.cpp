#include<bits/stdc++.h>

using namespace std;

struct Node
{
 int data;
 Node *next;
};

void insert(Node **binptr, int x)
{
 Node *t = new Node;
 t->data=x;
 t->next=NULL;
 if(binptr[x]==NULL)
   {
    binptr[x]=t;
   }
 else
   {
    Node *p = binptr[x];
    while(p->next!=NULL)
         {
          p=p->next;
         }
    p->next=t;
   }
}

int del(Node **binptr, int x)
{
 Node *p = binptr[x];
 binptr[x]=binptr[x]->next;
 int val=p->data;
 delete p;
 return val;
}

void bucket_sort(int ar[], int n)
{
 int i,j,max = *max_element(ar,ar+n);
 Node **bucket = new Node*[max+1];
 for(i=0;i<max+1;i++)
    {
     bucket[i]=NULL;
    }
 for(i=0;i<n;i++)
    {
     insert(bucket,ar[i]);
    }
 i=j=0;
 while(i<max+1)
      {
       while(bucket[i]!=NULL)
            {
             ar[j++]=del(bucket,i);
            }
       i++;
      }
 delete []bucket;
}

void disp(int ar[], int n)
{
 for(int i=0;i<n;i++)
    {
     cout<<ar[i]<<" ";
    }
 cout<<"\n";
}


int main()
{
 int ar[]={8,3,7,4,9,2,6,5};
 bucket_sort(ar,8);
 disp(ar,8);
}

