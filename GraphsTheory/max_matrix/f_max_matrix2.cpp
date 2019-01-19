#include <algorithm>
#include <vector>
#include <queue>
#include <limits>
#include <iostream>

using namespace std;

typedef vector<vector<int>> Matrix;

Matrix solve(Matrix);
int find_path(vector<int> &, const Matrix &);

int main()
{
	int n, m;
	cin >> n;
	cin >> m;

	Matrix mc(n + m + 2, vector<int>(n + m + 2));

	for (int i = 0; i < n + m + 2; ++i)
		for (int k = 0; k < n + m + 2; ++k)
		{
			if (i == 0 && k > 1 && k < n + 2)
			{
				int val;
				cin >> val;
				mc[i][k] = val;
				mc[k][i] = val;
			}
			else if (i == 1 && k >= n + 2)
			{
				int val;
				cin >> val;
				mc[i][k] = val;
				mc[k][i] = val;
			}
			else if (i > 1 && i < n + 2 && k >= n + 2)
			{
				int val = numeric_limits<int>::max();
				mc[i][k] = val;
				mc[k][i] = val;
			}
		}

	Matrix flow = solve(mc);

	int s = 0;
	for (int i = 0; i < n + m + 2; ++i)
		s += flow[0][i];
	cout << s << endl;
}

Matrix solve(Matrix c)
{
	Matrix f(c.size(), vector<int>(c.size()));

	int m;
	vector<int> path;
	while ((m = find_path(path, c)))
	{
		for (int i = 0; i < path.size() - 1; ++i)
		{
			int a = path[i + 1];
			int b = path[i];
			c[a][b] -= m;
			c[b][a] += m;
			f[a][b] += m;
			f[b][a] -= m;
		}
	}

	return f;
}

int find_path(vector<int> &path, const Matrix &mc)
{
	path.clear();

	queue<int> q;
	vector<int> visited(mc.size(), -1);
	q.push(0);
	visited[0] = 0;
	while (!q.empty() && q.front() != 1)
	{
		const int now = q.front();
		q.pop();

		for (int i = 0; i < mc.size(); ++i)
		{
			if (mc[now][i] && visited[i] == -1)
			{
				visited[i] = now;
				q.push(i);
			}
		}
	}

	if (q.empty())
		return 0;
	int m = 0x7fffffff;
	int cur = 1;
	while (cur)
	{
		path.push_back(cur);
		m = min(m, mc[visited[cur]][cur]);
		cur = visited[cur];
	}

	path.push_back(0);

	return m;
}