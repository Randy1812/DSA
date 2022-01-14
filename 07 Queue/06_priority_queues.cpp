#include<iostream>

using namespace std;

class Queue
{
 private:
    int front,rear,size;
    char *Q;
 public:
    Queue(){front=rear=-1;size=10;Q=new char[10];}
    Queue(int size){front=rear=-1;this->size=size;Q=new char[size];}
    void enqueue(char x);
    char dequeue();
    void disp();
    bool isempty(){return front==rear;}
};

void Queue::enqueue(char x)
{
 if(rear==size-1)
   {
    cout<<"Queue is full.\n";
    return;
   }
 rear++;
 Q[rear]=x;
}

char Queue::dequeue()
{
 if(front==rear)
   {
    cout<<"Queue is empty.\n";
    return -1;
   }
 front++;
 char x=Q[front];
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

void insert(char el[], int prio[], int size, Queue &q1,Queue &q2,Queue &q3)
{
  for(int i=0;i<size;i++)
    {
     switch(prio[i])
           {
            case 1:q1.enqueue(el[i]);
                    break;
            case 2:q2.enqueue(el[i]);
                    break;
            case 3:q3.enqueue(el[i]);
                    break;
           }
    }
 q1.disp();
 q2.disp();
 q3.disp();
 cout<<"\n\n";
}

char del(Queue &q1,Queue &q2,Queue &q3)
{
 if(!q1.isempty())
   {
    return q1.dequeue();
   }
 else
   {
    if(!q2.isempty())
      {
       return q2.dequeue();
      }
    else
      {
       return q3.dequeue();
      }
   }
}

void dis(Queue &q1,Queue &q2,Queue &q3)
{
 q1.disp();
 q2.disp();
 q3.disp();
 cout<<"\n\n";
}

int main()
{
 Queue q1,q2,q3;
 char el[12]={'A','B','C','D','E','F','G','H','I','J','K','L'};
 int prio[12]={1,1,2,3,2,1,2,3,2,2,1,1};
 insert(el,prio,12,q1,q2,q3);
 for(int i=0;i<12;i++)
    {
     del(q1,q2,q3);
     dis(q1,q2,q3);
    }
}
