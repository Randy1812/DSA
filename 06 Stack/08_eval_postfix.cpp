//Done Using STL

#include<bits/stdc++.h>

using namespace std;

int main()
{
 stack<int> st;
 int num1,num2;
 string s="35*62/+4-";
 for(auto i:s)
    {
     if(isdigit(i))
       {
        st.push(i-48);
       }
     else
       {
        num1=st.top();
        st.pop();
        num2=st.top();
        st.pop();
        switch(i)
              {
               case '+':st.push(num2+num1);
                        break;
               case '-':st.push(num2-num1);
                        break;
               case '*':st.push(num2*num1);
                        break;
               case '/':st.push(num2/num1);
                        break;
              }
       }
    }
 cout<<st.top();
}
