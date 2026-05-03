#include <iostream>
#include <stack>
#include <queue>

using namespace std;

/*
1022. Sum of Root To Leaf Binary Numbers
https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/description/

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
    int sumRootToLeaf(TreeNode *root)
    {
        return dfs(root, 0);
    }

    int dfs(TreeNode *node, int current)
    {
        if (!node)
            return 0;

        // Build binary number
        current = current * 2 + node->val;

        // If leaf → return value
        if (!node->left && !node->right)
        {
            return current;
        }

        // Sum of left and right paths
        return dfs(node->left, current) +
               dfs(node->right, current);
    }
};
