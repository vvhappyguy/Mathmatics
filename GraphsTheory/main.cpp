#include <iostream> // IO
#include <vector>   // Connected nodes
#include <set>      // For DFS and BFS
#include <stack>    // DFS
#include <queue>    // BFS

using namespace std;

static ulong counter = 0;

class Node
{
  public:
    short unsigned int value;
    vector<Node *> connected_nodes;
    ulong number;
    Node(short unsigned int _value, vector<Node *> _connected_nodes)
    {
        this->number = counter++;
        this->value = _value;
        this->connected_nodes.swap(_connected_nodes);
        for (Node *node : connected_nodes)
            node->connected_nodes.push_back(this);
    };

    ~Node()
    {
        this->value = 0;
        this->connected_nodes.clear();
    };
};

class MatrixAdj
{
  public:
    ushort **matrix;
    ushort *size;
    MatrixAdj(vector<Node *> nodes)
    {
        this->size = new ushort;
        *this->size = nodes.size();
        this->matrix = new ushort *[*size];
        for (ushort i = 0; i < *size; i++)
            this->matrix[i] = new ushort[*size];

        for (Node *n : nodes)
        {
            matrix[n->number][n->number] = 0;
            for (Node *conn_n : n->connected_nodes)
            {
                matrix[n->number][conn_n->number] = 1;
                matrix[conn_n->number][n->number] = 1;
            }
        }
    };

    ~MatrixAdj()
    {
        for (ushort count = 0; count < *this->size; count++)
            delete[] matrix[count];
    };

    void print()
    {
        std::cout << "Print matrix:" << std::endl;
        for (ushort i = 0; i < *this->size; i++)
        {
            for (ushort j = 0; j < *this->size; j++)
                std::cout << matrix[i][j] << "\t";
            std::cout << endl;
        }
        std::cout << std::flush;
    };
};

int main(int args, char *argv[])
{
    vector<Node *> all_nodes;
    Node a(1, all_nodes);
    all_nodes.push_back(&a);
    Node b(2, all_nodes);
    all_nodes.push_back(&b);

    for (Node *node : all_nodes)
    {
        cout << "It's " << node->number << " with value = " << node->value << endl;
        if (node->connected_nodes.size() > 0)
        {
            cout << "There are connected nodes: " << endl;
            for (Node *conn_node : node->connected_nodes)
            {
                cout << conn_node->number << "\t";
            }
        }

        else
            cout << "No connected nodes" << endl;
        cout << endl;
    }

    MatrixAdj* matrix = new MatrixAdj(all_nodes);
    matrix->print();
    delete matrix;

    return 0;
}