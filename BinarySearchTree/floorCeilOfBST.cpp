#include <iostream>
#include <stack>
#include <queue>

using namespace std;

/*
Floor and Ceil in a BST
https://takeuforward.org/plus/dsa/problems/floor-and-ceil-in-a-bst
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
    vector<int> floorCeilBST(TreeNode *root, int x)
    {
        int floor = -1, ceil = -1;

        TreeNode *curr = root;

        while (curr)
        {

            if (curr->val == x)
            {
                floor = ceil = curr->val;
                break;
            }

            if (curr->val < x)
            {
                floor = curr->val; // valid floor candidate
                curr = curr->right; //go right (to find bigger candidates)
            }
            else
            {
                ceil = curr->val; // valid ceil candidate 
                curr = curr->left; //go left (to find smaller valid candidates)
            }
        }

        return {floor, ceil};
    }
};
