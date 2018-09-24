#include <iostream>

/*
    V - вершины
    E - рёбра
*/

/*
    Algroitm by steps:
    --------------------
    1. Get Input Values +
    1.1. Count of Vs: n +
    1.2. Init graph's matrix +
    1.3. Get values of flow V by V (on every E) +
    2. Non-computer practice
    2.1. Read more about max_flow by graph algoritm
    2.2. Make two examples(excs) using pen)) Later, for tests
    2.3. Take a plan by brain!
*/

class GraphMatrix
{
    public:
        GraphMatrix(); // C-tor
        ~GraphMatrix(); // D-tor
        void printMatrix();
    private:
        int** matrix;
        int n;
};

GraphMatrix::GraphMatrix()
{
    this->n = 0;
    std::cout << "Please write your \"n\" value (count of Vs):\n";
    std::cin >> n;
    this->matrix = new int*[n];
    for (size_t i = 0; i < n; i++)
        this->matrix[i] = new int[n];

    unsigned short int value = 0;
    std::cout << "\n Now you should enter your matrix values." << std::endl; 
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < n; j++)
            if (i != j)
            {
                std::cout << "M[" << i+1 << "][" << j+1 << "] = ";
                std:: cin >> value;
                this->matrix[i][j] = value;
            }
            else
                this->matrix[i][j] = -1;

};

GraphMatrix::~GraphMatrix()
{
    for(int i = 0; i < this->n; i++)
        delete [] this->matrix[i];
}

void GraphMatrix::printMatrix()
{
    for (int i = 0; i < this->n; i++)
        for (int j = 0; j < this->n; j++)
        {
            if(j == 0)
                std::cout << "\n";
            if(i != j)
                std::cout << " ";
            std::cout << this->matrix[i][j] << " ";
        }
    std::cout << std::flush;
    std::cout << std::endl;
}

int main(int args, char* argv[])
{
    std::cout << "Hello!" << std::endl;
    GraphMatrix* gp = new GraphMatrix();
    gp->printMatrix();
    delete gp;
    return 0;
}