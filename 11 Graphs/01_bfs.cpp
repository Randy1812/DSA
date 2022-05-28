#include<bits/stdc++.h>

using namespace std;

void BFS(int G[][7], int start, int n)
{
 int i=start;
 int visited[7]={0};
 int u,v;
 queue<int> q;
 cout<<i;
 visited[i]=1;
 q.push(i);
 while(!q.empty())
      {
       u=q.front();
       q.pop();
       for(v=1;v<=n;v++)
          {
           if(G[u][v]==1 && !visited[v])
             {
              cout<<v;
              visited[v]=1;
              q.push(v);
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
 BFS(G,5,7);
 return 0;
}
