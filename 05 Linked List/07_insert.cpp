#include<iostream>

using namespace std;

struct node
{
 int data;
 node *next;
}*first=NULL,*last=NULL;

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

int count(node *p)
{
 if(p==NULL)
   {
    return 0;
   }
 else
   {
    return count(p->next)+1;
   }
}

void insert(node *p, int pos, int x)
{
 int i;
 if(pos<0 || pos>count(p))
    return;
 node *t = new node;
 t->data = x;
 if(pos==0)
   {
    t->next=first;
    first=t;
   }
 else
   {
    for(i=0;i<pos-1;i++)
        p=p->next;
    t->next=p->next;
    p->next=t;
   }
}

void insert_last(int x)
{
 node *t = new node;
 t->data = x;
 t->next = NULL;
 if(first==NULL)
   {
    first=last=t;
   }
 else
   {
    last->next=t;
    last=t;
   }
}

void insert_sorted(node *first, int x)
{
 node *t,*q=NULL;
 t = new node;
 t->data=x;
 t->next=NULL;
 if(first==NULL)
    first=t;
 else
   {
    while(p && p->data<x)
         {
          q=p;
          p=p->next;
         }
    if(p==first)
      {
       t->next=first;
       first=t;
      }
    else
      {
       t->next=q->next;
       q->next=t;
      }
   }
}

int main()
{
 for(int i=1;i<=10;i++)
    insert(first,i-1,i);
 disp(first);
}
