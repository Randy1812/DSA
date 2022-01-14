#include<iostream>

#ifndef Queuecpp.h
#define Queuecpp_h

using namespace std;

class Node
{
 public:
    Node *left,*right;
    int data;
};

class Queue
{
 private:
    int front,rear,size;
    Node **Q;
 public:
    Queue(){front=rear=-1;size=10;Q=new Node*[10];}
    Queue(int size){front=rear=-1;this->size=size;Q=new Node*[size];}
    void enqueue(Node *x);
    Node* dequeue();
    void disp();
    bool isempty(){return front==rear;}
};

void Queue::enqueue(Node *x)
{
 if(rear==size-1)
   {
    cout<<"Queue is full.\n";
    return;
   }
 rear++;
 Q[rear]=x;
}

Node* Queue::dequeue()
{
 if(front==rear)
   {
    cout<<"Queue is empty.\n";
    return NULL;
   }
 front++;
 Node *x=Q[front];
 if(front==rear)
   {
    front=rear=-1;
   }
 return x;
}

void Queue::disp()
{
 for(int i=front+1;i<=rear;i++)
    {
     cout<<Q[i]<<" ";
    }
 cout<<"\n";
}

#endif

