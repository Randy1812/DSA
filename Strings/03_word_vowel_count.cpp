#include<iostream>

using namespace std;

int main()
{
 char s[] = "How are you?";
 int i,vct=0,cct=0,wct=1;
 for(i=0;s[i]!='\0';i++)
    {
     if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')
       {
        vct++;
       }
     else if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))
       {
       cct++;
       }
     if(s[i] == ' ' && s[i-1] != ' ')
       {
        wct++;
       }
    }
 cout<<"Vowels : "<<vct;
 cout<<"\nConsonants : "<<cct;
 cout<<"\nWords : "<<wct;
}
