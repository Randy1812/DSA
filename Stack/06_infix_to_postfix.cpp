#include<bits/stdc++.h>

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
// string infix="a+b*c";
// string infix="a+b*c-d/e";




 Stack st;
 string postfix="";
 for(auto i:infix)
    {
     if(isalnum(i))
       {
        postfix+=i;
       }
     else
       {
        if(st.isempty())
          {
           st.push(i);
          }
        else
          {
           if(i=='+' || i=='-')
             {
              while(!st.isempty())
                   {
                    postfix+=st.pop();
                   }
              st.push(i);
             }
           else
             {
              while(st.stacktop()=='*' || st.stacktop()=='/')
                   {
                    postfix+=st.pop();
                   }
              st.push(i);
             }
          }
       }
    }
 while(!st.isempty())
      {
       postfix+=st.pop();
      }
 cout<<postfix;
}

