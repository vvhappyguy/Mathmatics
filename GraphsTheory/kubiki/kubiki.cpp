#include "stdio.h"
#include "iostream"
#include <fstream>
#include "ctype.h"

using namespace std;

int n;
int capacity[1001][1001], flow[1001][1001], color[1001], pred[1001], head, tail, numbers[1002];
string s, s1;

int bfs(int start, int stock)
{
  int u, v;
  for (u = 0; u < n; u++)
    color[u] = 0;

  head = 0;
  tail = 0;

  numbers[tail] = start;
  tail++;
  color[start] = 1;
  pred[start] = -1;
  while (head != tail)
  {
    u = numbers[head];
    head++;
    color[u] = 2;
    for (v = 0; v < n; v++)
    {
      if (color[v] == 0 && (capacity[u][v] - flow[u][v]) > 0)
      {
        numbers[tail] = v;
        tail++;
        color[v] = 1;
        pred[v] = u;
      }
    }
  }
  if (color[stock] == 2)
    return 1;
  else
    return 0;
}

int max_flow(int start, int stock)
{
  int i, j, u;
  int maxflow = 0;
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
      flow[i][j] = 0;
  }
  while (bfs(start, stock))
  {
    int min_flow = 1000;
    for (u = stock; pred[u] >= 0; u = pred[u])
    {
      min_flow = min(min_flow, (capacity[pred[u]][u] - flow[pred[u]][u]));
    }
    for (u = stock; pred[u] >= 0; u = pred[u])
    {
      flow[pred[u]][u] += min_flow;
      flow[u][pred[u]] -= min_flow;
    }
    maxflow += min_flow;
  }
  if (maxflow == s.size())
    cout << "YES";
  else
    cout << "NO";
  cout << endl;
  return maxflow;
}

int main()
{
  int n1 = 0;
  int i, j;
  int k = 0;
  string line;
  ifstream myfile("test8.in");
  if (myfile.is_open())
  {
    while (!myfile.eof())
    {
      k++;
      getline(myfile, line);
      if (k <= 2)
        s = line;
      if (k > 2)
      {
        s1 += line;
      }
      if (k == 1)
      {
        for (i = 0; i < s.size(); i++)
        {
          n1 += int(s[i]) - 48;
          n1 *= 10;
        }
        n1 /= 10;
      }
      if (k == n1 + 2)
        break;
    }
  }
  for (j = 0; j < n1 + s.size() + 2; j++)
    for (i = 0; i < n1 + s.size() + 2; i++)
      capacity[j][i] = 0;
  k = 0;
  int t = 0;
  for (j = 0; j < n1; j++)
  {
    for (i = 0; i < s.size(); i++)
    {
      for (k = t; k < t + 6; k++)
      {
        if (s1[k] == s[i])
        {
          capacity[j][i + n1 + 1] = 1;
          break;
        }
        else
        {
          capacity[j][i + n1 + 1] = 0;
        }
      }
    }
    t += 6;
  }
  for (i = 0; i < n1; i++)
    capacity[n1][i] = 1;
  for (j = n1 + 1; j < n1 + s.size() + 1; j++)
    capacity[j][n1 + s.size() + 1] = 1;
  n = n1 + s.size() + 2;
  cout << "Max flow = " << max_flow(n1, n1 + s.size() + 1);
  return 0;
}
