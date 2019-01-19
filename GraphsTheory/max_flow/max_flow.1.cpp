#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>

using namespace std; 

typedef vector<vector<int> > Matrix;	

Matrix solve(Matrix); 
int find_path(vector<int>&, const Matrix&); 

int main()
{
	int n;
	cin >> n;
	Matrix mc(n, vector<int>(n));

	for(int i = 0; i < n; ++i)
		for(int k = 0; k < n; ++k)
			cin >> mc[i][k];

	Matrix flow = solve(mc);

	int s = 0;
	for(int i = 0; i < n; ++i)
		s += flow[0][i];
	cout << s << endl;
}


Matrix solve(Matrix c)
{
	
	Matrix f(c.size(), vector<int>(c.size()));

	int m;
	vector<int> path;
	
	while((m = find_path(path, c)))
	{
		
		for(int i = 0; i < path.size() - 1; ++i)
		{
			
			int a = path[i+1];
			int b = path[i];
			c[a][b] -= m;
			c[b][a] += m;
			f[a][b] += m;
			f[b][a] -= m;
		}
	}

	return f;
}



int find_path(vector<int>& path, const Matrix& mc)
{
	path.clear(); 

	queue<int> q;
	vector<int> visited(mc.size(), -1);
	
	q.push(0);
	visited[0] = 0;
	
	while(!q.empty() && q.front() != 1)
	{
		
		const int now = q.front();
		q.pop(); 

		
		for(int i = 0; i < mc.size(); ++i)
		{
			if(mc[now][i] && visited[i] == -1)
			{
				visited[i] = now;
				q.push(i);
			}
		}
	}

	if(q.empty()) return 0;

	
	int m = 0x7fffffff; 
	int cur = 1; 
	while(cur) 
	{
		path.push_back(cur);
		m = min(m, mc[visited[cur]][cur]); 
		cur = visited[cur]; 
	}

	path.push_back(0);

	return m;
}

