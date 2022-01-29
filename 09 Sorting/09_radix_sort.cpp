#include<bits/stdc++.h>

using namespace std;

struct Node
{
 int data;
 Node *next;
};

void insert(Node **binptr, int x, int idx)
{
 Node *t = new Node;
 t->data=x;
 t->next=NULL;
 if(binptr[idx]==NULL)
   {
    binptr[idx]=t;
   }
 else
   {
    Node *p=binptr[idx];
    while(p->next!=NULL)
         {
          p=p->next;
         }
    p->next=t;
   }
}

int del(Node **binptr, int x)
{
 Node *t = binptr[x];
 int val=t->data;
 binptr[x]=binptr[x]->next;
 delete t;
 return val;
}

int countdigs(int num)
{
 int ct=0;
 while(num!=0)
      {
       num/=10;
       ct++;
      }
 return ct;
}

int getidx(int num, int pass)
{
 return (int)(num/pow(10,pass))%10;
}

void radix_sort(int ar[], int n)
{
 int max=*max_element(ar,ar+n);
 int numpass =countdigs(max);
 Node **bins = new Node*[10];
 for(int i=0;i<10;i++)
    {
     bins[i]=NULL;
    }
 for(int pass=0;pass<numpass;pass++)
    {
     for(int i=0;i<n;i++)
        {
         int binidx=getidx(ar[i],pass);
         insert(bins,ar[i],binidx);
        }
     int i=0,j=0;
     while(i<10)
          {
           while(bins[i]!=NULL)
                {
                 ar[j++]=del(bins,i);
                }
           i++;
          }
     for(int k=0;k<10;k++)
        {
         bins[k]=NULL;
        }
    }
 delete []bins;
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
 int ar[]={237,146,259,342,152,163,235,42,36,62};
 radix_sort(ar,10);
 disp(ar,10);
}

