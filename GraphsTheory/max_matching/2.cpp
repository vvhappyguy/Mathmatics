#include "stdio.h"
#include "iostream"

using namespace std;

#define INT_MAX 0x7fffffff
int n1,m1,n;
int capacity[1001][1001], flow[1001][1001], color[1001], pred[1001], head, tail, numbers[1002];


int bfs(int start, int stock)
{
  int u,v;
  for( u = 0; u < n; u++ )
    color[u]=0;

  head=0;
  tail=0;

  numbers[tail] = start;
  tail++;
  color[start] = 1;
  pred[start]= -1;
  while(head!=tail)
  {
    u=numbers[head];
    head++;
    color[u] = 2;

    for(v = 0; v < n; v++){
     if(color[v] == 0 && (capacity[u][v]-flow[u][v]) > 0) {
        numbers[tail] = v;
        tail++;
        color[v] = 1;
        pred[v]=u;
     }
    }
  }
  if(color[stock] == 2)
    return 1;
    else return 0;
}

int max_flow(int start, int stock)
{
  int i,j,u;
  int maxflow=0;
  for( i = 0; i < n; i++ )
    {
      for( j = 0; j < n; j++)
      flow[i][j]=0;
    }
  while(bfs(start,stock))
    {
      int min_flow=1000;
      for(u = stock; pred[u] >= 0; u=pred[u])
      {
        min_flow=min(min_flow, ( capacity[pred[u]][u] - flow[pred[u]][u] ) );
      }
      for(u = stock; pred[u] >= 0; u=pred[u])
      {
        flow[pred[u]][u] += min_flow;
        flow[u][pred[u]] -= min_flow;
      }
      maxflow+=min_flow;
    }
  return maxflow;
}



int main()
{

  freopen ("test6.in", "r", stdin);
  cin >> n1;
  cin >> m1;
  cout << "Count of V = " << n1+m1 << endl;
  int i,j;
  for (i=0;i<m1+n1+2;i++)
    for (j=0;j<m1+n1+2;j++)
        capacity[i][j]=0;
  for( i = 0; i < m1+n1; i++ )
    {
      for( j = 0; j < m1+n1; j++ ){
        capacity[i][j]=INT_MAX;
      }
    }
    for (j=0;j<n1;j++)
    {
        cin >> capacity[m1+n1][j];
    }
    for (j=n1;j<n1+m1+2;j++){
        capacity[m1+n1][j]=0;
    }
    for (i=0;i<n1+m1+2;i++)
    {
        capacity[i][m1+n1+1]=0;
    }
    for (i=n1;i<n1+m1;i++){
        cin >> capacity[i][m1+n1+1];
    }
    n=m1+n1+2;
    cout << "Max flow = " << max_flow(m1+n1,m1+n1+1);

  return 0;
}
