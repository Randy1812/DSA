#include<iostream>

using namespace std;

struct node
{
 int data;
 node *next;
}*first=NULL;

void recursive_disp(node *p)
{
 if(p!=NULL)
      {
       cout<<p->data;
       if(p->next != NULL)
         {
          cout<<"->";
         }
       recursive_disp(p->next);
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

int main()
{
 int A[] = {3,5,7,10,15};
 create(A,5);
 recursive_disp(first);
}

