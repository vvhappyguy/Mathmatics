#include <iostream>
#include "../max_flow/max_flow.hpp"

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	MaxFlow::Matrix g(n + m + 2, vector<int>(n + m + 2));

	for(int i = 0; i < n; ++i)
		cin >> g[0][i + 2];

	for(int i = 0; i < m; ++i)
		cin >> g[2 + n + i][1];

	for(int i = 0; i < n; ++i)
		for(int k = 0; k < m; ++k)
			g[2+i][2+n+k] = 0x7fffffff;

	MaxFlow solver;
	auto f = solver.solve(g);

	int s = 0;
	for(int i = 0; i < f.size(); ++i)
		s += f[0][i];
	cout << s << endl;
}

