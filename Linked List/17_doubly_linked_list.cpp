#include<iostream>

using namespace std;

struct Node
{
 int data;
 Node *next,*prev;
}*first=NULL;

void create(int A[], int n)
{
 Node *t,*last;
 int i;
 first = new Node;
 first->data=A[0];
 first->prev=first->next=NULL;
 last=first;
 for(i=1;i<n;i++)
    {
     t = new Node;
     t->data=A[i];
     t->next=last->next;
     t->prev=last;
     last->next=t;
     last=t;
    }
}


void disp(Node *p)
{
 while(p)
      {
       cout<<p->data;
       if(p->next!=NULL){cout<<"->";}
       p=p->next;
      }
      cout<<"\n";
}

int length(Node *p)
{
 int len=0;
 while(p!=NULL)
      {
       len++;
       p=p->next;
      }
 return len;
}

void insert(Node *p, int index, int x)
{
 Node *t;
 if(index<0 || index>length(p))
   {
    return;
   }
 if(index==0)
   {
    t=new Node;
    t->data=x;
    t->prev=NULL;
    t->next=first;
    first->prev=t;
    first=t;
   }
 else
   {
    t = new Node;
    t->data=x;
    for(int i=0;i<index-1;i++)
       {
        p=p->next;
       }
    t->next=p->next;
    t->prev=p;
    if(t->next)
      {
       t->next->prev=t;
      }
    t->prev->next=t;
   }
}

int del(Node *p, int index)
{
 if(index<1 || index>length(p))
   {
    return -1;
   }
 if(index==1)
   {
    first=first->next;
    if(first)
      {
       first->prev=NULL;
      }
    int x=p->data;
    delete p;
   }
 else
   {
    for(int i=0;i<index-1;i++)
       {
        p=p->next;
       }
    p->prev->next=p->next;
    if(p->next)
      {
       p->next->prev=p->prev;
      }
    int x=p->data;
    delete p;
    return x;
   }
}

void rev(Node *p)
{
 Node *temp;
 while(p!=NULL)
      {
       temp=p->next;
       p->next=p->prev;
       p->prev=temp;
       p=p->prev;
       if(p!=NULL && p->next==NULL)
         {
          first=p;
         }
      }
}

int main()
{
 int A[]={10,20,30,40,50};
 create(A,5);
 cout<<"Length is : "<< length(first)<<endl;
 disp(first);
 insert(first,5,60);
 cout<<endl;
 disp(first);
 del(first,6);
 cout<<endl;
 disp(first);
 rev(first);
 cout<<endl;
 disp(first);
}
