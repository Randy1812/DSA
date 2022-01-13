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
 if((q->rear+1)%q->size==q->front)
   {
    cout<<"Queue is full.\n";
    return;
   }
 q->rear=(q->rear+1)%q->size;
 q->Q[q->rear]=x;
}

int dequeue(Queue *q)
{
 if(q->front==q->rear)
   {
    cout<<"Queue is empty.\n";
    return -1;
   }
 q->front = (q->front+1)%q->size;
 int x = q->Q[q->front];
 if(q->front==q->rear)
   {
    q->front=q->rear=0;
   }
 return x;
}

void create(Queue *q, int size)
{
 q->size=size;
 q->front=q->rear=0;
 q->Q = new int(q->size);
}

void disp(Queue *q)
{
 int i=q->front+1;
 do
   {
    cout<<q->Q[i]<<" ";
    i=(i+1)%q->size;
   }while(i!=(q->rear+1)%q->size);
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
