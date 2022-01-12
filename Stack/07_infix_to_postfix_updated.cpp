//Done Using STL
#include<bits/stdc++.h>

using namespace std;

int opre(char c)
{
 if(c=='-' || c=='+')
   {
    return 1;
   }
 else if(c=='*' || c=='/')
   {
    return 3;
   }
 else if(c=='^')
   {
    return 6;
   }
 else if(c=='(')
   {
    return 7;
   }
 else if(c==')')
   {
    return 0;
   }
}

int ipre(char c)
{
  if(c=='-' || c=='+')
   {
    return 2;
   }
 else if(c=='*' || c=='/')
   {
    return 4;
   }
 else if(c=='^')
   {
    return 5;
   }
 else if(c=='(')
   {
    return 0;
   }
}

int main()
{
 string s = "((a+b)*c)-d^e^f";
 string op="";
 stack<char> st;
 for(auto i:s)
    {
     if(isalnum(i))
       {
        op+=i;
       }
     else
       {
        if(st.empty())
          {
           st.push(i);
          }
        else
          {
           if(opre(i)==ipre(st.top()))
             {
              st.pop();
             }
           else
             {
              while(opre(i)<=ipre(st.top()))
                   {
                    if(st.top()!='(' && st.top()!=')')
                       op+=st.top();
                    st.pop();
                    if(st.empty())
                       break;
                   }
              st.push(i);
             }
          }
       }
    }
 while(!st.empty())
      {
       op+=st.top();
       st.pop();
      }
 cout<<"\n"<<op;
}
