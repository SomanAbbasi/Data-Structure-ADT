#include <iostream>
#include <stack>
#include <queue>

using namespace std;

/*
538. Convert BST to Greater Tree

https://leetcode.com/problems/convert-bst-to-greater-tree/

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
    int totalSum = 0;
    TreeNode *convertBST(TreeNode *root)
    {

        if (!root)
            return nullptr;
        convertBST(root->right); // larger value;

        totalSum+=root->val; // sum it
        root->val=totalSum; // update node 

        convertBST(root->left);  // smaller val

        return root;
    }
};
