
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

node* search (node* p, int key)
{
 while(p!=NULL)
      {
       if(key == p->data)
         {
          cout<<key<<" Found";
          return p;
         }
       p=p->next;
      }
 return NULL;
}

node* recursive_search(node* p, int key)
{
 if(p==NULL)
   {
    cout<<"\nNot Found";
    return NULL;
   }
 if(key == p->data)
   {
    cout<<"\nFound";
    return p;
   }
 recursive_search(p->next,key);
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
