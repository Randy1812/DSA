#include<iostream>

using namespace std;

struct Node
{
 int data;
 Node *next;
}*head;

void create(int A[], int n)
{
 int i;
 Node *t,*tail;
 head = new Node;
 head->data=A[0];
 head->next=head;
 tail=head;
 for(i=1;i<n;i++)
    {
     t=new Node();
     t->data=A[i];
     t->next=head;
     tail->next=t;
     tail=t;
    }
}

void display(Node *p)
{
 do
  {
   cout<<p->data;
   if(p->next!=head){cout<<"->";}
   p=p->next;
  }while(p!=head);
}

void rdisplay(Node *p)
{
 static int flag=0;
 if(p!=head || flag==0)
   {
    flag=1;
    cout<<p->data;
    if(p->next!=head){cout<<"->";}
    rdisplay(p->next);
   }
   flag=0;
}

int length(Node *p)
{
 int count=0;
 do
   {
    count++;
    p=p->next;
   }while(p!=head);
 return count;
}

void insert(int index, int x)
{
 Node *t,*p;
 if(index<0 || index>length(head))
   {
    return;
   }
 if(index==0)
   {
    t=new Node;
    t->data=x;
    if(head==NULL)
      {
       head=t;
       head->next=head;
      }
    else
      {
       p=head;
       while(p->next!=head)
            {
             p=p->next;
            }
       t->next=head;
       p->next=t;
       head=t;
      }
   }
 else
   {
    p=head;
    for(int i=0;i<index-1;i++)
       {
        p=p->next;
       }
    t=new Node;
    t->data=x;
    t->next=p->next;
    p->next=t;
   }
}

int del(int index)
{
 Node *p=head,*q=NULL;
 if(index<1 || index>length(head))
   {
    return -1;
   }
 if(index==1)
   {
    while(p->next!=head)
         {
          p=p->next;
         }
    if(p==head)
      {
       int x = p->data;
       delete head;
       head=NULL;
       return x;
      }
    else
      {
       p->next=head->next;
       int x = head->data;
       delete head;
       head=p->next;
       return x;
      }
   }
 else
   {
    for(int i=0;i<index-2;i++)
       {
        p=p->next;
       };
    q=p->next;
    p->next=q->next;
    int x = q->data;
    delete q;
    return x;
   }
}

int main()
{
 int A[]={2,3,4,5,6};
 create(A,5);
 display(head);
 cout<<endl;
 insert(0,10);
 rdisplay(head);
 cout<<endl;
 del(1);
 rdisplay(head);
}
