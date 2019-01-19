#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>

using namespace std; 

typedef vector<vector<int> > Matrix;	

Matrix solve(Matrix); // находит макс. поток
int find_path(vector<int>&, const Matrix&); // ищет произвольный путь в ост. сети

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

// основная функция, возвращает макс. поток.
Matrix solve(Matrix c)
{
	// f - поток, то есть матрица, совпадающая по размеру с матрицей c
	Matrix f(c.size(), vector<int>(c.size()));

	int m;
	vector<int> path;
	// пока удается найти произвольный путь в c, при этом m - его проп. способность
	// если find_path вернет 0, то m = 0, цикл завершится
	while((m = find_path(path, c)))
	{
		// перебираем все ребра (пара вершин) от t к s (в обратном порядке, так
		// удобнее)
		for(int i = 0; i < path.size() - 1; ++i)
		{
			// вдоль ребра в c вычитаем m, обратно -- прибавляем. в f - наоборот
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

// find_path - обычный BFS (поиск в ширину)
// в path сохраняется найденный путь из 0 в 1 (но в обратном порядке, то есть 
// из 1 в 0), а возвращается его пропускная способность

int find_path(vector<int>& path, const Matrix& mc)
{
	path.clear(); // очищаем переданный нам вектор для формирования нового пути

	queue<int> q;
	vector<int> visited(mc.size(), -1);
	// visited хранит не просто информацию о том, какие вершины посещены, но 
	// и номер вершины, из которой каждая посещена. это нужно для 
	// нахождения пути. Изначально все элементы visited равны -1,
	// например, если visited[2] = 5 - это означает, что вершина 2
	// посещена из 5-й вершины.

	// начинаем путь из нулевой вершины
	q.push(0);
	visited[0] = 0;
	// пока очередь не пуста и первый ее элемент - не 1.
	while(!q.empty() && q.front() != 1)
	{
		// копируем первый элемент очереди в now
		const int now = q.front();
		q.pop(); // удаляем его из очереди

		// перебираем всех непосещенных соседей вершины now
		for(int i = 0; i < mc.size(); ++i)
		{
			if(mc[now][i] && visited[i] == -1)
			{
			// i - непосещенный (-1) сосед now, отмечаем его как посещенного из now
				visited[i] = now;
				q.push(i);
			}
		}
	}
	// из этого while можно выйти в 2-х случаях:
	//   1. очередь пуста (q.empty()), значит, от 0 до 1 мы не добрались
	//   2. первый элемент очереди - вершина 1, значит путь из 0 в 1 существует

	if(q.empty()) return 0;

	// формируем путь из 1 в 0
	int m = 0x7fffffff; // самый большой положительный int (2**31 - 1)
	int cur = 1; // номер текущей вершины
	while(cur) // пока не дошли до вершины cur = 0
	{
		path.push_back(cur);
		m = min(m, mc[visited[cur]][cur]); // макс пропускная способность
		cur = visited[cur]; // cur = вершина, из которой мы пришли в cur в BFS
	}

	path.push_back(0); // добавляем последнюю вершину - 0.

	return m;
}

