#include<bits/stdc++.h>

using namespace std;

void DFS(int G[][7], int start, int n)
{
 static int visited[7]={0};
 if(visited[start]==0)
   {
    cout<<start;
    visited[start]=1;
    for(int v=1;v<=n;v++)
       {
        if(G[start][v] && !visited[v])
          {
           DFS(G,v,n);
          }
       }
   }
}

int main()
{
 int G[7][7]={{0,0,0,0,0,0,0},
              {0,0,1,1,0,0,0},
              {0,1,0,0,1,0,0},
              {0,1,0,0,1,0,0},
              {0,0,1,1,0,1,1},
              {0,0,0,0,1,0,0},
              {0,0,0,0,1,0,0},
             };
 DFS(G,1,7);
}
