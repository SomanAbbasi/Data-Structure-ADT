#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <string>
using namespace std;

/*
https://www.geeksforgeeks.org/dsa/breadth-first-search-or-bfs-for-a-graph/
*/

// BFS - Directed Graph - Adjacency List
void bfs1(int start, vector<vector<int>> &adj, vector<bool> &visited)
{
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int nbr : adj[node])
        {
            if (!visited[nbr])
            {
                visited[nbr] = true;
                q.push(nbr);
            }
        }
    }
}

// BFS - Directed Graph - Adjacency Matrix
void bfs2(int start, vector<vector<int>> &mat, vector<bool> &visited, int V)
{
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int i = 0; i < V; i++)
        {
            if (mat[node][i] == 1 && !visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main()
{
    int V = 4;

    // DIRECTED graph adjacency list
    vector<vector<int>> adj(V);

    // edges (u -> v only)
    adj[0].push_back(1);
    adj[0].push_back(2);

    adj[1].push_back(3);

    adj[2].push_back(3);


    vector<bool> visited1(V, false);

    cout << "BFS Traversal (Directed Graph - List): ";

    for (int i = 0; i < V; i++)
    {
        if (!visited1[i])
        {
            bfs1(i, adj, visited1);
        }
    }

    cout << endl;

    // adjacency matrix (directed graph)
    vector<vector<int>> mat =
    {
        {0, 1, 1, 0},  // 0 -> 1,2
        {0, 0, 1, 0},  // 1 -> 2
        {0, 0, 0, 1},  // 2 -> 3
        {0, 0, 0, 0}   // 3 -> none
    };

    vector<bool> visited2(V, false);

    cout << "BFS Traversal (Directed Graph - Matrix): ";

    for (int i = 0; i < V; i++)
    {
        if (!visited2[i])
        {
            bfs2(i, mat, visited2, V);
        }
    }

    cout << endl;
}