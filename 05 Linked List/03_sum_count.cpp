#include<iostream>

using namespace std;

struct node
{
 int data;
 node *next;
}*first=NULL;

void disp(node *p)
{
 while(p!=NULL)
      {
       cout<<p->data;
       if(p->next != NULL)
         {
          cout<<"->";
         }
       p=p->next;
      }
}

void create(int A[], int n)
{
 int i;
 node *t,*last;
 first = new node;
 first->data = A[0];
 first->next = NULL;
 last=first;
 for(i=1;i<n;i++)
    {
     t = new node;
     t->data = A[i];
     t->next=NULL;
     last->next=t;
     last=t;
    }
}

void count(node *p)
{
 int ct=0;
 while(p!=NULL)
      {
       ct++;
       p=p->next;
      }
 cout<<"There are "<<ct<<" nodes.\n";
}

int count_recursive(node *p)
{
 if(p==NULL)
   {
    return 0;
   }
 else
   {
    return count_recursive(p->next)+1;
   }
}

void sum(node *p)
{
 int sum=0;
 while(p!=NULL)
      {
       sum+=p->data;
       p=p->next;
      }
 cout<<"There sum is "<<sum<<".\n";
}

int sum_recursive(node *p)
{
 if(p==NULL)
   {
    return 0;
   }
 else
   {
    return sum_recursive(p->next)+p->data;
   }
}

int main()
{
 int A[] = {3,5,7,10,15};
 create(A,5);
 disp(first);
 cout<<"\n";
 count(first);
 sum(first);
 cout<<"\nRecursive Count : "<<count_recursive(first);
 cout<<"\nRecursive Sum : "<<sum_recursive(first);
}

