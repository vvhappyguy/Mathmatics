#include <iostream>
#include <set>
#include <stack>
#include <vector>

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
        for (Node* node: connected_nodes)
            node->connected_nodes.push_back(this);
    };

    ~Node()
    {
        this->value = 0;
        this->connected_nodes.clear();
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

    return 0;
}