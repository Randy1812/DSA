#include<iostream>

using namespace std;

int main()
{
 char A[] = "python";
 char B[7],tp;
 int i,j;
 for(i=0;i<A[i]!='\0';i++);
 i--;
 for(j=0;i>=0;j++,i--)
    {
     B[j] = A[i];
    }
 B[j]='\0';
 cout<<A<<"\n";
 cout<<B<<"\n\n";
 for(i=0;A[i]!='\0';i++);
 for(j=0;j<i/2;j++)
    {
     tp = A[j];
     A[j] = A[i-j-1];
     A[i-j-1] = tp;
    }
 cout<<A;
}

