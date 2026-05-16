#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>

using namespace std;
/*

https://leetcode.com/problems/evaluate-boolean-binary-tree/description/?utm_source=chatgpt.com
*/
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool evaluateTree(TreeNode *root)
    {
        if (!root->left && !root->right)
        {
            return root->val == 1;
        }
        bool leftVal = evaluateTree(root->left);
        bool rightVal = evaluateTree(root->right);

        if (root->val == 2)
        {
            return leftVal || rightVal; 
        }
        else
        {
            return leftVal && rightVal; 
        }
    }
};

int main()
{
}