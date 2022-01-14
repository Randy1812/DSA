#include<iostream>

using namespace std;

struct Node
{
 int data;
 Node *next;
};

class Stack
{
 private:
    Node * top;
 public:
    Stack(){top=NULL;}
    void push(int x);
    int pop();
    void disp();
    bool isempty(){return top==NULL;}
};

void Stack::push(int x)
{
 Node *t = new Node;
 if(!t)
   {
    cout<<"Stack Overflow.\n";
    return;
   }
 else
   {
    t->data=x;
    t->next=top;
    top=t;
   }
}

int Stack::pop()
{
 int x=-1;
 if(top==NULL)
   {
    cout<<"Stack Underflow.\n";
   }
 else
   {
    x = top->data;
    Node *t = top;
    top=top->next;
    delete t;
   }
 return x;
}

void Stack::disp()
{
 Node *p = top;
 while(p!=NULL)
      {
       cout<<p->data<<" ";
       p=p->next;
      }
 cout<<endl;
}

void enqueue(Stack &st1, Stack &st2, int x)
{
 st1.push(x);
}

int dequeue(Stack &st1, Stack &st2)
{
 int x=-1;
 if(st2.isempty())
   {
    if(st1.isempty())
      {
       cout<<"Queue is empty.\n";
       return x;
      }
    else
      {
       while(!st1.isempty())
            {
             x=st1.pop();
             st2.push(x);
            }
      }
   }
 x=st2.pop();
 return x;
}

int main()
{
 Stack st1,st2;
 for(int i=1;i<=10;i++)
     enqueue(st1,st2,i);
 for(int i=0;i<10;i++)
    cout<<dequeue(st1,st2)<<" ";
}

