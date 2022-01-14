#include<iostream>

using namespace std;

struct node
{
 int data;
 node *next;
}*first=NULL,*second=NULL,*third=NULL;

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

void merge()
{
 node *last = NULL;
 if(first->data < second->data)
   {
    third=last=first;
    first=first->next;
    last->next=NULL;
   }
 else
   {
    third=last=second;
    second=second->next;
    last->next=NULL;
   }
 while(first!=NULL && second!=NULL)
      {
       if(first->data < second->data)
         {
          last->next=first;
          last=first;
          first=first->next;
          last->next=NULL;
         }
       else
        {
         last->next=second;
         last=second;
         second=second->next;
         last->next=NULL;
        }
      }
 if(first!=NULL)
   {
    last->next=first;
   }
 else
   {
    last->next=second;
   }
}

int main()
{
 int A[] = {2,8,10,15};
 int B[] = {4,7,12,14};
 create(A,4);
 create2(B,4);
 disp(first);
 cout<<"\n\n";
 disp(second);
 cout<<"\n\n";
 merge();
 cout<<"\n\n";
 disp(third);
}

