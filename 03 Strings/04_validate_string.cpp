#include<iostream>

using namespace std;

int valid(char *name)
{
 int i;
 for(i=0;name[i]!='\0';i++)
    {
     if(!(name[i]>='a' && name[i]<='z') && !(name[i]>='A' && name[i]<='Z') && !(name[i]>=48 && name[i] <= 58))
       {
        return 0;
       }
    }
 return 1;
}

int main()
{
 char *name = "Ani?321";
 if(valid(name))
   {
    cout<<"Valid";
   }
 else
   {
    cout<<"Invalid";
   }
}

