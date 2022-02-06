#include<iostream>
#define SIZE 10

using namespace std;

int hsh1(int key)
{
 return key%SIZE;
}

int hsh2(int key)
{
 return 7-(key%7);
}

int probe(int H[], int key)
{
 int index=hsh1(key);
 int i=0;
 while(H[(hsh1(key)+i*hsh2(key))%SIZE]!=0)
      {
       i++;
      }
 return (hsh1(key)+i*hsh2(key))%SIZE;
}

void insert(int H[], int key)
{
 int index=hsh1(key);
 if(H[index]!=0)
   {
    index=probe(H,key);
   }
 H[index]=key;
}

int main()
{
 int HT[10]={0};
 insert(HT,5);
 insert(HT,25);
 insert(HT,15);
 insert(HT,35);
 insert(HT,95);
 for(int i=0;i<SIZE;i++)
    {
     cout<<i<<" : "<<HT[i]<<"\n";
    }
}

