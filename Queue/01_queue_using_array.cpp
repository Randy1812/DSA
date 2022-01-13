#include<iostream>

using namespace std;

struct Queue
{
 int size;
 int front,rear;
 int *Q;
};

void enqueue(Queue *q, int x)
{
 if(q->rear==q->size-1)
   {
    cout<<"Queue is full.\n";
    return;
   }
 else
   {
    q->rear++;
    q->Q[q->rear]=x;
   }
}

int dequeue(Queue *q)
{
 if(q->front==q->rear)
   {
    cout<<"Queue is empty.\n";
    return -1;
   }
 q->front++;
 int x=q->Q[q->front];
 if(q->front==q->rear)
   {
    q->front==q->rear=-1;
   }
 return x;
}

void create(Queue *q, int size)
{
 q->size=size;
 q->front=q->rear=-1;
 q->Q = new int(q->size);
}

void disp(Queue *q)
{
 for(int i=q->front+1;i<=q->rear;i++)
    {
     cout<<q->Q[i]<<" ";
    }
 cout<<"\n";
}

int main()
{
 Queue *q;
 create(q,5);
 for(int i=1;i<=5;i++)
    {
     enqueue(q,i);
    }
 disp(q);
 dequeue(q);
 disp(q);
}
