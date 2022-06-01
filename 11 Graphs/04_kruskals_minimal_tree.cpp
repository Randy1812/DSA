#include<bits/stdc++.h>

#define I INT_MAX

using namespace std;

int edges[3][9]={{1,1,2,2,3,4,4,5,5},
                 {2,6,3,7,4,5,7,6,7},
                 {25,5,12,10,8,16,14,20,18}
                 };

int st[8] = {-1,-1,-1,-1,-1,-1,-1,-1};

int included[9] = {0}, t[2][6];


int Myunion(int u, int v)
{
 if(st[u]<st[v])
   {
    st[u]+=st[v];
    st[v]=u;
   }
 else
   {
    st[v]+=st[u];
    st[u]=v;
   }
}

int find(int u)
{
 int x=u,v=0;
 while(st[x]>0)
      {
       x=st[x];
      }
 while(u!=x)
      {
       v=st[u];
       st[u]=x;
       u=v;
      }
 return x;
}

int main()
{
 int i=0,j,k,n=7,e=9,min=I,u,v;
 while(i<n-1)
      {
       min=I;
        for(j=0;j<e;j++)
           {
            if(included[j]==0 && edges[2][j]<min)
              {
               min=edges[2][j];
               k=j;
               u=edges[0][j];
               v=edges[1][j];
              }
           }
       if(find(u)!=find(v))
         {
          t[0][i]=u;
          t[1][i]=v;
          Myunion(find(u),find(v));
          i++;
         }
         included[k]=1;
      }

 for(i=0;i<n-1;i++)
    {
     cout<<"("<<t[0][i]<<","<<t[1][i]<<")\n";
    }
}
