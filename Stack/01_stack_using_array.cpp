#include<iostream>

using namespace std;

struct Stack
{
 int size;
 int top;
 int *s;
};

void push(Stack *st, int x)
{
 if(st->top==st->size-1)
   {
   cout<<"Stack is full.(Stack Overflow)";
   return;
   }
 else
   {
    st->s[++st->top]=x;
   }
}

int pop(Stack *st)
{
 if(st->top==-1)
   {
    cout<<"Stack is empty.(Stack Underflow)";
    return -1;
   }
 else
   return st->s[st->top--];
}

int peek(Stack *st, int pos)
{
 if(st->top-pos+1<0)
   {
    cout<<"Invalid Position";
    return -1;
   }
 else
   {
    return st->s[st->top-pos+1];
   }
}

bool isempty(Stack *st)
{
 return st->top==-1;
}

bool isfull(Stack *st)
{
 return st->top==st->size-1;
}

void disp(Stack *st)
{
 for(int i=0;i<=st->top;i++)
    {
     cout<<st->s[i]<<" ";
    }
}

int main()
{
 Stack *st;
 cout<<"Enter the size of the stack : ";
 cin>>st->size;
 st->s = new int[st->size];
 st->top=-1;
 for(int i=0;i<5;i++)
    {
     push(st,i+1);
    }
 disp(st);
 cout<<"\n";
 pop(st);
 disp(st);
 cout<<"\n";
 push(st,6);
 disp(st);
 cout<<"\n";
}
