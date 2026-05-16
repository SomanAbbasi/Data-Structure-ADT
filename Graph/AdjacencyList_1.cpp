#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <string>
using namespace std;

/*
https://www.geeksforgeeks.org/dsa/graph-and-its-representations/
*/

vector<vector<int>> createGraph(int V, vector<vector<int>> &edges)
{
    vector<vector<int>> res(V);
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        res[u].push_back(v);

        // for directed graph we did not write this 
        res[v].push_back(u);

    }

    return res;
}

int main()
{

    int V = 3; // no. of  Nodes (Vetices)

    // list of edges
    vector<vector<int>> edges = {
        {0, 1}, 
        {0, 2},
        {1, 2}
    };

    vector<vector<int>>res=createGraph(V,edges);

    cout << "Adjacency List Representation:" << endl;
    for (int i = 0; i < V; i++)
    {
        cout<<i<<" : ";

        for (int j:res[i])
        {
            cout<<j<<" ";
        }
        cout << endl;
    }

}
