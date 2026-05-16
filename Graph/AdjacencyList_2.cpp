#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <string>
using namespace std;



struct Node
{
    int data;
    Node *next;
};

// create node
Node *createNode(int val)
{
    Node *newNode = new Node();
    newNode->data = val;
    newNode->next = nullptr;
    return newNode;
}


// insert v into adjancent list of u
void addEdge(Node *adj[], int u, int v)
{
    Node *newNode = createNode(v);

    // insert at beginning
    newNode->next = adj[u];

    adj[u] = newNode;
}

void printGraph(Node *adj[], int V)
{
    for (int i = 0; i < V; i++)
    {
        cout << i << " -> ";

        Node *temp = adj[i];
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}
int main()
{

    int V = 3; // no. of  Nodes (Vetices)

    // list of edges
    vector<vector<int>> edges = {
        {0, 1},
        {0, 2},
        {1, 2}};

    // array of linked list
    Node *adj[V];

    for (int i = 0; i < V; i++)
    {
        adj[i] = nullptr;
    }

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        addEdge(adj, u, v);
        // for directed we not write this line
        addEdge(adj, v, u);
    }

    printGraph(adj, V);
}
