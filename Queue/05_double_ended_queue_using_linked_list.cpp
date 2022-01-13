#include<iostream>

using namespace std;

struct Node
{
 int data;
 Node *prev,*next;
}*front=NULL,*rear=NULL;

void enqueue_front(int x)
{
 Node *t = new Node;
 if(!t)
   {
    cout<<"Memory Overflow. Queue is full.\n";
    return;
   }
 else
   {
    t->data=x;
    t->next=NULL;
    t->prev=NULL;
    if(front==NULL)
      {
       front=rear=t;
      }
    else
      {
       t->next=front;
       front->prev=t;
       front=t;
      }
   }
}

void enqueue_rear(int x)
{
 Node *t = new Node;
 if(!t)
   {
    cout<<"Memory Overflow. Queue is full.\n";
    return;
   }
 else
   {
    t->data=x;
    t->next=NULL;
    t->prev=NULL;
    if(front==NULL)
      {
       front=rear=t;
      }
    else
      {
       rear->next=t;
       t->prev=rear;
       rear=t;
      }
   }
}

int dequeue_front()
{
 if(front==NULL)
   {
    cout<<"Queue is empty.\n";
    return -1;
   }
 else
   {
    Node *p = front;
    int x = p->data;
    if(front==rear)
      {
       front=rear=NULL;
      }
    else
      {
       front=front->next;
       front->prev=NULL;
      }
    delete p;
    return x;
   }
}

int dequeue_rear()
{
  if(front==NULL)
   {
    cout<<"Queue is empty.\n";
    return -1;
   }
 else
   {
    Node *p = rear;
    int x = p->data;
    if(rear==front)
      {
       rear=front=NULL;
      }
    else
      {
       rear=rear->prev;
       rear->next=NULL;
      }
    delete p;
    return x;
   }
}

void disp()
{
 if(front==NULL)
   {
    cout<<"Queue is empty.\n";
    return;
   }
 Node *p = front;
 while(p!=NULL)
      {
       cout<<p->data<<" ";
       p=p->next;
      }
 cout<<"\n";
}

int main()
{
 for(int i=1;i<=5;i++)
    {
     enqueue_rear(i);
    }
 disp();
  for(int i=6;i<=10;i++)
    {
     enqueue_front(i);
    }
 disp();
 for(int i=0;i<5;i++)
    {
     dequeue_front();
    }
 disp();
 for(int i=0;i<5;i++)
    {
     dequeue_rear();
    }
 disp();
}
