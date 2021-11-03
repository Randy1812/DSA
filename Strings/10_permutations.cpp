#include<iostream>

using namespace std;

void perms(char s[], int k)
{
 static int A[10] = {0};
 static char res[10];
 int i;
 if(s[k] == '\0')
   {
    res[k] = '\0';
    cout<<res<<"\n";
   }
 else
   {
    for(i=0;s[i]!='\0';i++)
    {
     if(A[i] == 0)
       {
        res[k] = s[i];
        A[i] = 1;
        perms(s,k+1);
        A[i] = 0;
       }
    }
   }
}

void permswp(char s[], int l, int h)
{
 int i;
 if(l==h)
   {
    cout<<s<<"\n";
   }
 else
   {
    for(i=l;i<=h;i++)
       {
        swap(s[i],s[l]);
        permswp(s,l+1,h);
        swap(s[i],s[l]);
       }
   }
}

int main()
{
 char S[] = "ABC";
 permswp(S,0,2);
}

