#include<iostream>

using namespace std;

struct Node
{
 int data;
 Node *next,*prev;
}*head;

void create(int A[], int n)
{
 Node *last,*t;
 head = new Node;
 head->data=A[0];
 head->next=head;
 head->prev=head;
 last=head;
 for(int i=1;i<n;i++)
    {
     t = new Node;
     t->data=A[i];
     t->next=last->next;
     t->prev=last;
     last->next=t;
     t->next->prev=t;
     last=t;
    }
}

int length(Node *p)
{
 int ct=0;
 do
   {
    p=p->next;
    ct++;
   }while(p!=head);
 return ct;
}

void disp(Node *p)
{
 do
   {
    cout<<p->data;
    if(p->next!=head)
      {
       cout<<"->";
      }
    p=p->next;
   }while(p!=head);
   cout<<"\n";
}

void insert(int index, int x)
{
 Node *p = head;
 if(index<0 || index>length(p))
   {
    return;
   }
 if(index==0)
   {
    Node *t = new Node;
    t->data = x;
    if(head==NULL)
      {
       t->next=head;
       t->prev=head;
       head=t;
      }
    else
      {
       while(p->next!=head)
            {
             p=p->next;
            }
       t->next=head;
       t->prev=p;
       p->next=t;
       head->prev=t;
       head=t;
      }
   }
 else
   {
    for(int i=0;i<index-1;i++)
       {
        p=p->next;
       }
    Node *t=new Node;
    t->data=x;
    t->next=p->next;
    t->prev=p;
    p->next=t;
    t->next->prev=t;
   }
}

int del(int index)
{
 if(index<1 || index>length(head))
   {
    return -1;
   }
 Node *p=head,*q=NULL;
 if(index==1)
   {
    q=p->prev;
    q->next=p->next;
    p->next->prev=q;
    head=p->next;
    int x=p->data;
    delete p;
    return x;
   }
 else
   {
    for(int i=0;i<index-2;i++)
       {
        p=p->next;
       }
    q=p->next;
    p->next=q->next;
    q->next->prev=p;
    int x = q->data;
    delete q;
    return x;
   }
}

int main()
{
 int A[]={10,20,30,40,50};
 create(A,5);
 disp(head);
 insert(0,60);
 disp(head);
 del(5);
 disp(head);
}
