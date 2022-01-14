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

void rev()
{
 node *p=first,*q=NULL,*r=NULL;
 while(p!=NULL)
 {
  r=q;
  q=p;
  p=p->next;
  q->next=r;
 }
 first=q;
}

void recursive_rev(node *q, node *p)
{
 if(p!=NULL)
   {
    recursive_rev(p,p->next);
    p->next=q;
   }
 else
   {
    first=q;
   }
}

int main()
{
 int A[] = {3,5,7,10,15};
 create(A,5);
 disp(first);
 rev();
 cout<<"\n\n";
 disp(first);
 cout<<"\n\n";
 recursive_rev(NULL,first);
 disp(first);
}

