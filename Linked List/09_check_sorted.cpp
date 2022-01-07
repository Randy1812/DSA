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

bool check_srted(){
 int x=INT_MIN;
 node *p = first;
 while(p!=NULL)
 {
  if(p->data<x)
    {
     return false;
    }
    x=p->data;
    p=p->next;
 }
 return true;
}
int main()
{
 int A[] = {3,5,7,10,15};
 create(A,5);
 disp(first);
 if(check_srted)
   {
    cout<<"\nSorted";
   }
 else
   {
   cout<<"\nNot Sorted";
   }
}
