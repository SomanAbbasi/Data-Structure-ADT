#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>

using namespace std;

/*
https://leetcode.com/problems/cousins-in-binary-tree/description/?utm_source=chatgpt.com
993. Cousins in Binary Tree
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
    bool isSiblings(TreeNode *root, int x, int y)
    {
        if (!root)
            return false;

        if (root->left != nullptr && root->right != nullptr && root->left->val == x && root->right->val == y)
        {
            return true;
        }
        if (root->left != nullptr && root->right != nullptr && root->left->val == y && root->right->val == x)
        {
            return true;
        }

        return isSiblings(root->left,x,y) || isSiblings(root->right,x,y);

    }
    int level(TreeNode *root, int value, int lev)
    {
        if (!root)
            return 0;
        if (root->val == value)
        {
            return lev;
        }
        int l = level(root->left, value, lev + 1);
        if (l != 0)
            return l;

        return level(root->right, value, lev + 1);
    }
    bool isCousins(TreeNode *root, int x, int y)
    {
        if (!root)
            return false;

        int xLevel = level(root, x, 1);

        int yLevel = level(root, y, 1);

        if(xLevel==0 || yLevel==0) return false;

        if(xLevel==yLevel && !isSiblings(root,x,y)){
            return true;
        }
        return false;
        
    }
};

int main()
{
}