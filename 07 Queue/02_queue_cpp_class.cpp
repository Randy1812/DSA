#include<iostream>

using namespace std;

class Queue
{
 private:
    int front,rear,size;
    int *Q;
 public:
    Queue(){front=rear=-1;size=10;Q=new int[10];}
    Queue(int size){front=rear=-1;this->size=size;Q=new int[size];}
    void enqueue(int x);
    int dequeue();
    void disp();
};

void Queue::enqueue(int x)
{
 if(rear==size-1)
   {
    cout<<"Queue is full.\n";
    return;
   }
 rear++;
 Q[rear]=x;
}

int Queue::dequeue()
{
 if(front==rear)
   {
    cout<<"Queue is empty.\n";
    return -1;
   }
 front++;
 int x=Q[front];
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

int main()
{
 Queue q;
 for(int i=01;i<=10;i++)
    {
     q.enqueue(i);
    }
 q.disp();
 q.dequeue();
 q.disp();
}
