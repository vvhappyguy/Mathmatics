#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

typedef vector<vector<int>> Matrix;

vector<int> mt;
vector<char> used;

Matrix solve(Matrix);
int find_path(vector<int> &, const Matrix &);
bool vengr(int v, vector<vector<int>> g);

int main()
{
	char method;
	cout << "Фалкерсон | Венгерский(f\\v)? : ";
	cin >> method;

	if (method == 'f')
	{

		int n, m;
		cin >> n >> m;

		Matrix mc(n + m + 2, vector<int>(n + m + 2));

		for (int i = 0; i < n + m + 2; i++)
			for (int j = 0; j < n + m + 2; j++)
			{
				if (i == j)
					mc[i][j] = 0;
				else if (i == 0 && j < n + 2 && j != 1)
				{
					mc[i][j] = 1;
					mc[j][i] = 1;
				}
				else if (i == 1 && j >= n + 2)
				{
					mc[i][j] = 1;
					mc[j][i] = 1;
				}
			}
		for (int i = 2; i < n + 2; ++i)
		{
			int j;
			cin >> j;
			for (int k = 0; k < j; ++k)
			{
				int val;
				cin >> val;
				mc[i][val + 1 + n] = 1;
				mc[val + 1 + n][i] = 1;
			}
		}

		Matrix flow = solve(mc);

		int s = 0;
		for (int i = 0; i < n + m + 2; ++i)
			s += flow[0][i];
		cout << s << endl;
	}

	else if (method == 'v')
	{

		int n, m;
		cin >> n >> m;
		vector<vector<int>> mc;

		for (int i = 0; i < n; i++)
		{
			vector<int> row;
			row.assign(m, 0);
			mc.push_back(row);
		}

		for (int i = 0; i < n; i++)
		{
			int num;
			cin >> num;
			for (int j = 0; j < num; j++)
			{
				int val;
				cin >> val;
				mc[i][val] = 1;
			}
		}

		mt.assign(m, -1);
		for (int v = 0; v < n; ++v)
		{
			used.assign(n, false);
			vengr(v, mc);
		}
		int res = 0;
		for (int i = 0; i < m; ++i)
			if (mt[i] != -1)
			{
				res++;
			}
		cout << res << endl;
	}
}

bool vengr(int v, vector<vector<int>> g)
{
	if (used[v])
		return false;
	used[v] = true;
	for (size_t i = 0; i < g[v].size(); ++i)
	{
		if (g[v][i] && (mt[i] == -1 || vengr(mt[i], g)))
		{
			mt[i] = v;
			return true;
		}
	}
	return false;
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
