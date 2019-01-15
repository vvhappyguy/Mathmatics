#include "stdio.h"
#include "conio.h"
#include "iostream"
#include "limits.h"

using namespace std;


int n;
int capacity[1001][1001], flow[1001][1001], color[1001], pred[1001], head, tail, numbers[1002],max_flow;


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
     if(color[v] == 0 && capacity[u][v] > 0 && capacity[u][v]>max_flow) {
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

int maxflow(int start, int stock)
{
  int i,j,u;
  int max_flow=0;
  for( i = 0; i < n; i++ )
    {
      for( j = 0; j < n; j++)
      flow[i][j]=0;
    }
  while(bfs(start,stock))
    {
      int min_flow=INT_MAX;
      for(u = stock; pred[u] >= 0; u=pred[u])
      {
        min_flow=min(min_flow, capacity[pred[u]][u]);
      }
      for(u = stock; pred[u] >= 0; u=pred[u])
      {

            if (min_flow>max_flow){
                max_flow=min_flow;
            }


      }
      for (i=0;i<n+1;i++)
            for (j=0;j<n+1;j++)
                if (capacity[i][j]<=max_flow)
                    capacity[i][j]=0;
    }
  return max_flow;
}



int main()
{

  freopen ("test7.in", "r", stdin); // берём число вершин и матрицу смежности из файла
  cin >> n;
  cout << "Count of V = " << n << endl;
  int i,j;
  for( i = 0; i < n; i++ )
    {
      for( j = 0; j < n; j++ ){
        cin >> capacity[i][j];
      }
    }
    cout << "Max flow = " << maxflow(0,1);
  return 0;
}
