#include<iostream>

using namespace std;

int main()
{
 char A[] = "finding";
 int hsh[26]={0};
 int i;
 for(i=0;A[i]!='\0';i++)
    {
     hsh[A[i]-97] += 1;
    }
 for(i=0;i<26;i++)
    {
     if(hsh[i]>=1)
       {
        cout<<(char)(i+97) << " : " <<hsh[i]<<"\n";
       }
    }
}

