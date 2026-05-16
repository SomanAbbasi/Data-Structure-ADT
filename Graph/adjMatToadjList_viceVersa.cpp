#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <string>
using namespace std;
// Adj matrix to Adj List

vector<vector<int>> adjMatrixToadjList(vector<vector<int>> &adjMat, int V)
{
    vector<vector<int>> adjList(V);

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            /*
            If matrix is undirected:
            mat[i][j] = mat[j][i]
            code still works without changes because:
            i→j and j→i both exist
            list automatically builds both sides
*/
            if (adjMat[i][j] !=0)
            {
                adjList[i].push_back(j);
            }
        }
    }
    return adjList;
}

vector<vector<int>> adjListToadjMatrix(vector<vector<int>> &adjList, int V)
{

    vector<vector<int>> adjMat(V, vector<int>(V, 0));
    for (int u = 0; u < V; u++)
    {
        /* work both for directed and undirected graph*/
        for (int v : adjList[u])
        {
            adjMat[u][v] = 1;
        }
    }

    return adjMat;

}

int main()
{

    int V = 3; // no. of  Nodes (Vetices)

    // list of edges
    vector<vector<int>> edges = {
        {0, 1},
        {0, 2},
        {1, 2}};
}
