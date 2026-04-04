#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <deque>
#include<unordered_map>
using namespace std;


/*
https://leetcode.com/problems/different-ways-to-add-parentheses/description/?envType=problem-list-v2&envId=recursion&authuser=0
*/
class Solution
{
private:
    unordered_map<string, vector<int>> memo;

public:
    vector<int> diffWaysToCompute(string expression)
    {
         if (memo.count(expression)) return memo[expression];

        vector<int> res;
        for (int i = 0; i < expression.size(); i++)
        {
            char c = expression[i];
            // split on operator
            if (c == '+' || c == '-' || c == '*')
            {
                string left = expression.substr(0, i);
                string right = expression.substr(i + 1);
                vector<int> leftRes = diffWaysToCompute(left);
                vector<int> rightRes = diffWaysToCompute(right);
                for (int l : leftRes)
                {
                    for (int r : rightRes)
                    {
                        if (c == '+')
                            res.push_back(l + r);
                        else if (c == '-')
                            res.push_back(l - r);
                        else if (c == '*')
                            res.push_back(l * r);
                    }
                }
            }
        }
        // if no operator found it's just a number
        if (res.empty())
            res.push_back(stoi(expression));

        memo[expression] = res;

        return res;
    }
};

int main()
{
}