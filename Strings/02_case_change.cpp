#include<iostream>

using namespace std;

int main()
{
 char s[] = "WelCome";
 int i;
 //Upper to Lower
// for(i=0; s[i]!='\0';i++)
//    {
//     s[i]+=32;
//    }
// cout<<s;
// Toggle Case
 for(i=0;i<s[i]!='\0';i++)
    {
     if(s[i]>='a' && s[i]<='z')
       {
        s[i]-=32;
       }
     else if(s[i]>='A' && s[i]<='Z')
       {
        s[i]+=32;
       }
    }
 cout<<s;
}

