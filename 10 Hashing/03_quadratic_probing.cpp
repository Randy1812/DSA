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
 while(H[(index+i*i)%SIZE]!=0)
      {
       i++;
      }
 return (index+i*i)%SIZE;
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
 insert(HT,23);
 insert(HT,43);
 insert(HT,13);
 insert(HT,17);
 for(int i=0;i<SIZE;i++)
    {
     cout<<i<<" : "<<HT[i]<<"\n";
    }
}

