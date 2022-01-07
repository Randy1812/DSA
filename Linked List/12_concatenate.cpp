#include<iostream>

using namespace std;

struct node
{
 int data;
 node *next;
}*first=NULL,*second=NULL;

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

void create2(int B[], int n)
{
 int i;
 node *t,*last;
 second = new node;
 second->data = B[0];
 second->next = NULL;
 last=second;
 for(i=1;i<n;i++)
    {
     t = new node;
     t->data = B[i];
     t->next=NULL;
     last->next=t;
     last=t;
    }
}

void concatenate(node *p, node*q)
{
 while(p->next!=NULL)
 {
  p=p->next;
 }
 p->next=q;
 q=NULL;
}

int main()
{
 int A[] = {2,9,6,8};
 int B[] = {10,4,7};
 create(A,4);
 create2(B,3);
 disp(first);
 cout<<"\n\n";
 disp(second);
 cout<<"\n\n";
 concatenate(first,second);
 cout<<"\n\n";
 disp(first);
}

