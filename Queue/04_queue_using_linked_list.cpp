#include<iostream>

using namespace std;

struct Node
{
 int data;
 Node *next;
}*front=NULL,*rear=NULL;

void enqueue(int x)
{
 Node *t = new Node;
 if(!t)
   {
    cout<<"Memory Overflow.Queue is full.\n";
    return;
   }
 else
   {
    t->data=x;
    t->next=NULL;
    if(front==NULL)
      {
       front=rear=t;
      }
    else
      {
       rear->next=t;
       rear=t;
      }
   }
}

int dequeue()
{
 if(front==NULL)
   {
    cout<<"Queue is empty.\n";
    return -1;
   }
 else
   {
    int x;
    Node *p = front;
    x=p->data;
    front=front->next;
    delete p;
    return x;
   }
}

void disp()
{
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
     enqueue(i);
    }
 disp();
 dequeue();
 dequeue();
 disp();
 for(int i=6;i<=10;i++)
    enqueue(i);
 disp();
}
