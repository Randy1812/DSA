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

void rem_dup()
{
 node *p=first;
 node *q=p->next;
 while(p->next!=NULL)
      {
       if(p->data == q->data)
         {
          p->next=q->next;
          delete q;
          q=p->next;
         }
       else
         {
          p=q;
          q=q->next;
         }
      }
}

int main()
{
 int A[] = {3,5,5,8,8,8};
 create(A,5);
 disp(first);
 rem_dup();
 cout<<"\n\n";
 disp(first);
}

