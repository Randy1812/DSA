#include<bits/stdc++.h>

using namespace std;

int lcs(string s1, string s2)
{
 if(s1.size()==0 || s2.size()==0)
   {
    return 0;
   }
 if(s1[0]==s2[0])
   {
    return 1+lcs(s1.substr(1),s2.substr(1));
   }
 else
   {
    int a = lcs(s1.substr(1),s2);
    int b = lcs(s1,s2.substr(1));
    int c = lcs(s1.substr(1),s2.substr(1));
    return max(a,max(b,c));
   }
}

int main()
{
 string s1,s2;
 getline(cin,s1);
 getline(cin,s2);
// cout<<s1<<"\t"<<s2;
 cout<<lcs(s1,s2);
}
