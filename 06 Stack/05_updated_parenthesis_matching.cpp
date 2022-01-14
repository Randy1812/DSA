
#include<iostream>

using namespace std;

struct Node
{
 char data;
 Node *next;
};

class Stack
{
 private:
    Node * top;
 public:
    Stack(){top=NULL;}
    void push(char x);
    char pop();
    void disp();
    bool isempty(){return top==NULL;}
    char stacktop(){return top->data;};
};

void Stack::push(char x)
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

char Stack::pop()
{
 char x=-1;
 if(top==NULL)
   {
    cout<<"Stack Underflow\n";
    return NULL;
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

int isBalanced(string s)
{
 char c;
 Stack st;
 for(auto i:s)
    {
     if(i==')' || i=='}' || i==']')
       {
        if(st.isempty())
          {
           return 0;
          }
        else
          {
           if(st.stacktop()==i-1 || st.stacktop()==i-2)
             {
              st.pop();
             }
           else
             {
              return false;
             }
          }
       }
     if(i=='(' || i=='{' || i=='[')
       {
        st.push(i);
       }
    }
 return st.isempty();
}

int main()
{
 string s="{([a+b]*[c-d])/e}";
 if(isBalanced(s))
   {
    cout<<"Valid";
   }
 else
   {
    cout<<"Invalid";
   }
 cout<<" Parentheses";
}

