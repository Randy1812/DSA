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
    cout<<"Stack Overflow\n";
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
    cout<<"Stack Underflow\n";
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
 string s="((a+b)*(c-d)))";
 for(auto i:s)
    {
     if(i=='(')
       {
        st.push(1);
       }
     if(i==')')
       {
        if(st.pop()==-1)
          {
           cout<<"Invalid Parentheses";
           return 0;
          }
       }
    }
 if(!st.isempty())
   {
    cout<<"Invalid Parentheses";
    return 0;
   }
 cout<<"Valid Parentheses";
}

