#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <stack>
#include <climits>
using namespace std;

/*

994. Rotting Oranges

https://leetcode.com/problems/rotting-oranges/description/
*/

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int rows = grid.size();

        int cols = grid[0].size();
        int fresh =0;
        queue<tuple<int, int, int>> q; //(row,col,time)

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({i, j, 0});
                }
                else if (grid[i][j] == 1)
                {
                    fresh++;
                }
            }
        }

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        int rotted = 0;
        int minutes = 0;

        while (!q.empty())
        {
            auto [r,c,time]=q.front();
            q.pop();

            for(auto [dr,dc]:directions)
            {
                int nr=r+dr;
                int nc=c+dc;
                if(nr>=0 && nr<rows && nc>=0 && nc<cols && grid[nr][nc]==1)
                {
                    q.push({nr,nc,time+1});
                    grid[nr][nc]=2;
                    rotted++;
                    minutes=time+1;
                }
            }
        }
        


        return rotted == fresh ? minutes : -1;
    }
};

int main()
{
}