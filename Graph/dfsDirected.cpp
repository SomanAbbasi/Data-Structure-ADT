#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <string>
using namespace std;

/*
https://www.geeksforgeeks.org/dsa/depth-first-search-or-dfs-for-a-graph/
*/

// DFS - Directed Graph - Adjacency List
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

// DFS - Directed Graph - Adjacency Matrix
void dfs2(int node, vector<vector<int>> &mat, vector<bool> &visited, int V)
{
    visited[node] = true;
    cout << node << " ";

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

    // directed graph adjacency list
    vector<vector<int>> adj(V);

    // edges (DIRECTED: u -> v only)
    adj[0].push_back(1);
    adj[0].push_back(2);

    adj[1].push_back(3);

    adj[2].push_back(3);


    vector<bool> visited1(V, false);

    cout << "DFS Traversal (Directed Graph - List): ";

    for (int i = 0; i < V; i++)
    {
        if (!visited1[i])
        {
            dfs1(i, adj, visited1);
        }
    }

    cout << endl;

    // directed graph adjacency matrix
    vector<vector<int>> mat =
    {
        {0, 1, 1, 0},  // 0 -> 1,2
        {0, 0, 0, 1},  // 1 -> 3
        {0, 0, 0, 1},  // 2 -> 3
        {0, 0, 0, 0}   // 3 -> none
    };

    vector<bool> visited2(V, false);

    cout << "DFS Traversal (Directed Graph - Matrix): ";

    for (int i = 0; i < V; i++)
    {
        if (!visited2[i])
        {
            dfs2(i, mat, visited2, V);
        }
    }

    cout << endl;
}