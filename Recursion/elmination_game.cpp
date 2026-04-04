#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <deque>
#include <unordered_map>
using namespace std;

/*

https://leetcode.com/problems/elimination-game/description/?envType=problem-list-v2&envId=recursion&authuser=0
`
*/
class Solution
{
public:
    int solve(int n, bool isLeft)
    {
        if (n == 1)
            return 1;
        if (isLeft)
        {
            return 2 * solve(n / 2, false);
        }
        else
        {
            if (n % 2 == 1)
            {
                return 2 * solve(n / 2, true);
            }
            else
            {
                return 2 * solve(n / 2, true)-1;
            }
        }
    }
    int lastRemaining(int n)
    {
        return solve(n,true);

    }
};

int main()
{
}