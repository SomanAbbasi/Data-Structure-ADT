#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <string>
using namespace std;

/*
https://www.geeksforgeeks.org/dsa/depth-first-search-or-dfs-for-a-graph/
*/

// DFS (Undirected Graph - Adjacency List)
void dfs1(int node, vector<vector<int>> &adj, vector<bool> &visited)
{
    visited[node] = true;
    cout << node << " ";

    for (int nbr : adj[node])
    {
        if (!visited[nbr])
        {
            dfs1(nbr, adj, visited);
        }
    }
}

// DFS - Undirected Graph - Adjacency Matrix)
void dfs2(int node, vector<vector<int>> &mat, vector<bool> &visited, int V)
{
    visited[node] = true;
    cout << node << " ";

    // check all possible neighbors
    for (int i = 0; i < V; i++)
    {
        if (mat[node][i] == 1 && !visited[i])
        {
            dfs2(i, mat, visited, V);
        }
    }
}
int main()
{

    int V = 4;

    // undirected graph adjacency list
    vector<vector<int>> adj(V);

    // edges
    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[0].push_back(2);
    adj[2].push_back(0);

    adj[1].push_back(3);
    adj[3].push_back(1);

    adj[2].push_back(3);
    adj[3].push_back(2);

    vector<bool> visited1(V, false);
    cout << "DFS Traversal (Undirected Graph) : ";
    // in case graph is disconnected, we loop all nodes
    for (int i = 0; i < V; i++)
    {
        if (!visited1[i])
        {
            dfs1(i, adj, visited1);
        }
    }

    cout << endl;

    // adjacency matrix (undirected graph)
    vector<vector<int>> mat =
        {
            {0, 1, 1, 0},
            {1, 0, 0, 1},
            {1, 0, 0, 1},
            {0, 1, 1, 0}

        };

    vector<bool> visited2(V, false);

    cout << "DFS Traversal (Undirected Graph) : ";

    // handle disconnected graph
    for (int i = 0; i < V; i++)
    {
        if (!visited2[i])
        {
            dfs2(i, mat, visited2, V);
        }
    }

    cout << endl;
}
