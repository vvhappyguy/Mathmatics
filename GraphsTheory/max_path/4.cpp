#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

bool findChain (vector<int> &matrix, vector<int> &parents,
                vector<bool> &used, int start, int len){
    if (used[start]){
        return false;
    }
    used[start] = true;
    for (int i = 0; i < len; i++){
        if (matrix[start * len + i] && (parents[i] == -1 ||
            findChain(matrix, parents, used, parents[i], len))){
            parents[i] = start;
            return true;
        }
    }
    return false;
}

int main (int argc, char **argv){
    int n;
    int m;
    int count = 0;
    ifstream fin ("test6.in");
    fin >> n >> m;
    vector<int> matrix (n * m, 0);
    vector<int> parents (m, -1);
    vector<bool> used;

    for (int i = 0; i < n; i++){
        int j;
        fin >> j;
        for (int k = 0; k < j; k++){
            int p;
            fin >> p;
            matrix[i * m + p] = 1;
        }
    }

    for (int i = 0; i < n; i++){
        used.assign(n, false);
        findChain(matrix, parents, used, i, m);
    }

    for (int i = 0; i < m; i++){
        if (parents[i] != -1){
            count++;
        }
    }
    fin.close();
    fin.open("test6.out");
    int t;
    fin >> t;
    fin.close();
    cout << "Correct answer: " << t << endl;
    cout << "Calculated answer: " << count << endl;
}
