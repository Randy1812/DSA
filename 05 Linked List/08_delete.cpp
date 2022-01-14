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

void del(int pos)
{
 node *p=first;
 if(pos==1)
   {
    first=first->next;
    free(p);
   }
 else
   {
    node *q=NULL;
    for(int i=0;i<pos-1 && p;i++)
       {
        q=p;
        p=p->next;
       }
    if(p)
      {
       q->next=p->next;
       free(p);
      }
   }
}

int main()
{
 int A[] = {3,5,7,10,15};
 create(A,5);
 del(5);
 disp(first);
}

