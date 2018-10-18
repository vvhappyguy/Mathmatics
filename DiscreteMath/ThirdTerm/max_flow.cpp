#include <iostream>
#include <vector>


int** matrix;
short int n;
short int now;
std::vector<short int> put;
std::vector<short int> marked;
std::vector<short int> sme;
std::vector<int> potoki;
long int max_flow;

int main(int args, char* argv[])
{
    // freopen ("data.txt", "r", stdin);  // аргумент 1 - путь к файлу, 2 - режим ("r" || "w"), 3 - stdin || stdout
    std::cin >> n;
    matrix = new int*[n];
    for (size_t i = 0; i < n; i++)
        matrix[i] = new int[n];
    std::cout << "Количество вершин: " << n << std::endl;  
    int i,j;
    for( i = 0; i < n; i++ )
    {
      for( j = 0; j < n; j++ )
        std::cin >> matrix[i][j];
    }

    delete [] matrix;
    return 0;
}