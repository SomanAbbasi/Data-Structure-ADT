#include <iostream>
#include <stack>
#include <queue>

using namespace std;

/*
938. Range Sum of BST
https://leetcode.com/problems/range-sum-of-bst/description/*/

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
    int total = 0;

    int rangeSumBST(TreeNode *root, int low, int high)
    {
        if (!root)
            return 0;

        // If value is too small =>  ignore left subtree
        if (root->val < low)
            return rangeSumBST(root->right, low, high);

        // If value is too large =>  ignore right subtree
        if (root->val > high)
            return rangeSumBST(root->left, low, high);

        // If in range =>  take it + both sides
        return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    }
};
