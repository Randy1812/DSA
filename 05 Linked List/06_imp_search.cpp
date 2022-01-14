
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

//Make the element to be searched the first element of the linked list.

node* imp_search (node* p, int key)
{
 node *q = NULL;
 while(p!=NULL)
      {
       if(key==p->data)
         {
          q->next=p->next;
          p->next=first;
          first=p;
         }
       q=p;
       p=p->next;
      }
}

int main()
{
 int A[] = {3,5,7,10,15};
 create(A,5);
 disp(first);
 node *result;
 result = recursive_search(first,15);
 result = recursive_search(first,12);
}

