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

int max_element(node *p)
{
 int mx = INT_MIN;
 while(p!=NULL)
      {
       if(p->data > mx)
         {
          mx = p->data;
         }
       p=p->next;
      }
 return mx;
}

int recursive_max_element(node *p)
{
 if(p!=NULL)
   {
    return max(p->data,recursive_max_element(p->next));
   }
}

int main()
{
 int A[] = {3,5,7,10,15};
 create(A,5);
 disp(first);
  cout<<"\nMax Element : "<<max_element(first);
  cout<<"\nRecursive Max Element : "<<recursive_max_element(first);
}

