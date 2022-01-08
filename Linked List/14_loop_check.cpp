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

int check_loop(node *f)
{
 node *p=NULL,*q=NULL;
 while(p!=q)
      {
       if(p==NULL || q==NULL)
         {
          return 0;
         }
       p=p->next;
       q=q->next;
       q=q!=NULL?q->next:NULL;
      }
 return 1;
}

int main()
{
 node *t1,*t2;
 int A[] = {10,20,30,40,50};
 create(A,5);
 t1=first->next->next;
 t2=first->next->next->next->next;
 t2->next=t1;
 if(check_loop(first))
   {
    cout<<"There is a loop.";
   }
 else
   {
    cout<<"There is no loop.";
   }
}

