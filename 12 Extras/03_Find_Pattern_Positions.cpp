#include<bits/stdc++.h>

using namespace std;

int main()
{
 string txt="aabaacaadaabaaba",ptr="aaba";
// getline(cin,txt);
// getline(cin,ptr);
 int i,j;
 for(i=0;i<txt.length();i++)
    {
     for(j=0;ptr[j]==txt[i+j] && j<ptr.length();j++);
     if(j==ptr.length())
       {
        cout<<i<<"\n";
       }
    }
}
