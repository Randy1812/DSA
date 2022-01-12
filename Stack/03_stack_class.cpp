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
};

void Stack::push(int x)
{
 Node *t = new Node;
 if(!t)
   {
    cout<<"Stack Overflow";
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
    cout<<"Stack Underflow";
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

int main()
{
 Stack st;
 for(int i=1;i<=10;i++)
    {
     st.push(i);
    }
 st.disp();
 st.pop();
 st.disp();
}

