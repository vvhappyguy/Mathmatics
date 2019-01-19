#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int max_path()
{
    int res = 0;
    size_t n;
    cin >> n;

    vector<vector<int>> matrix;
    for (int i = 0; i < n; i++)
    {
        vector<int> row;
        for (int j = 0; j < n; j++)
        {
            int val;
            cin >> val;
            row.push_back(val);
        }
        matrix.push_back(row);
    }

    queue<int> changed;
    vector<int> max_val(n);
    changed.push(0);

    while (!changed.empty())
    {
        int cur = changed.front();
        changed.pop();
        if (cur == 0)
            for (int i = 0; i < n; i++)
                if (matrix[cur][i] != 0)
                {
                    max_val[i] = matrix[cur][i];
                    changed.push(i);
                }
        for (int i = 1; i < n; i++)
        {
            if (matrix[cur][i])
            {
                if (max_val[cur] > max_val[i])
                {
                    if (matrix[cur][i] > max_val[cur])
                    {
                        max_val[i] = max_val[cur];
                        if (i != 1)
                            changed.push(i);
                    }
                    else if (max_val[i] < matrix[cur][i])
                    {
                        max_val[i] = matrix[cur][i];
                        if (i != 1)
                            changed.push(i);
                    }
                }
            }
        }
    }
    res = max_val[1];
    return res;
}

int main()
{
    cout << max_path() << endl;
}