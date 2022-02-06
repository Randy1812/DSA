#include<iostream>
#define SIZE 10

using namespace std;

int hsh(int key)
{
 return key%SIZE;
}

int probe(int H[], int key)
{
 int index=hsh(key);
 int i=0;
 while(H[(index+i)%SIZE]!=0)
      {
       i++;
      }
 return (index+i)%SIZE;
}

void insert(int H[], int key)
{
 int index=hsh(key);
 if(H[index]!=0)
   {
    index=probe(H,key);
   }
 H[index]=key;
}

int main()
{
 int HT[10]={0};
 insert(HT,12);
 insert(HT,25);
 insert(HT,35);
 insert(HT,26);
 for(int i=0;i<SIZE;i++)
    {
     cout<<i<<" : "<<HT[i]<<"\n";
    }
}
