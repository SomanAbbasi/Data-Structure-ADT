#include <iostream>
#include <stack>
#include <queue>

using namespace std;

/*
230. Kth Smallest Element in a BST
https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
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

/*
So if we do an inorder traversal, we get:

Sorted order (ascending)

Inorder traversal:

1 → 2 → 3 → 4
If k = 1 → answer = 1
If k = 3 → answer = 3
*/

class Solution
{
public:
    int count = 0;
    int result = -1;
    void inorder(TreeNode *root, int k)
    {
        if (!root)
            return;

        inorder(root->left, k);

        count++;
        if (count == k)
        {
            result = root->val;
            return;
        }

        inorder(root->right, k);
    }
    int kthSmallest(TreeNode *root, int k)
    {
        inorder(root, k);
        return result;
    }
};
