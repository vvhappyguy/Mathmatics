
#ifndef MAXFLOW_HPP
#define MAXFLOW_HPP
#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>

class MaxFlow
{
public:
	typedef std::vector<std::vector<int> > Matrix;	
	Matrix solve(Matrix c)
	{
		std::vector<int> path;
		Matrix f(c.size(), std::vector<int>(c.size()));

		int m;
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

	static void print(const Matrix& m)
	{
		for(int i = 0; i < m.size(); ++i)
		{
			for(int k = 0; k < m[i].size(); ++k)
				std::cout << m[i][k] << " ";
			std::cout << std::endl; 
		}
	}


private:
	int find_path(std::vector<int>& path, const Matrix& mc)
	{
		std::queue<int> q;
		q.push(0);

		std::vector<int> visited(mc.size(), -1);

		visited[0] = 0;
		int cur = 1;
		while(!q.empty())
		{
			cur = q.front();
			q.pop();
			if(cur == 1) break;
			for(int i = 0; i < mc.size(); ++i)
			{
				if(mc[cur][i] && visited[i] == -1)
				{
					visited[i] = cur;
					q.push(i);
				}
			}
		}

		path.clear();
		if(cur != 1) return 0;

		int m = 0x7fffffff;
		while(cur)
		{
			path.push_back(cur);
			m = std::min(m, mc[visited[cur]][cur]);
			cur = visited[cur];
		}
		path.push_back(0);
		return m;
	}
};

#endif // MAXFLOW_HPP

