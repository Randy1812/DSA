#include<iostream>

using namespace std;

struct Node
{
 int data;
 Node *next;
}*top=NULL;

void push(int x)
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

int pop()
{
 if(top==NULL)
   {
    cout<<"Stack Underflow";
    return -1;
   }
 else
   {
    Node *p = top;
    int x = p->data;
    top=top->next;
    delete p;
    return x;
   }
}

int peek(int pos)
{
 int x=-1;
 Node *p=top;
 for(int i=0;i<pos-1&&p!=NULL;i++)
    {
     p=p->next;
    }
 if(p)
   return p->data;
 else
   return -1;
}

int stacktop()
{
 if(top)
   {
    return top->data;
   }
}

bool isfull()
{
 Node *t = new Node;
 int r = t?1:0;
 delete t;
 return r;
}

bool isempty()
{
 return top?0:1;
}

void disp()
{
 Node *p=top;
 while(p!=NULL)
      {
       cout<<p->data<<" ";
       p=p->next;
      }
 cout<<"\n";
}

int main()
{
 for(int i=1;i<=10;i++)
    push(i);
 disp();
 pop();
 disp();
}
