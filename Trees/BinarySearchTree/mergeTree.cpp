#include <iostream>
#include <stack>
#include <queue>

using namespace std;

/*

617. Merge Two Binary Trees
https://leetcode.com/problems/merge-two-binary-trees/description/

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
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        if (!root1 && !root2)
            return nullptr;

        // one null
        if (!root1)
            return root2;
        if (!root2)
            return root1;

        // both exits merge
        TreeNode *root = new TreeNode(root1->val + root2->val);

        root->left = mergeTrees(root1->left, root2->left);

        root->right = mergeTrees(root1->right, root1->right);

        return root;
    }
};

/*

 Iterative solution

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1) return root2;
        if (!root2) return root1;

        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root1, root2});

        while (!q.empty()) {
            auto [n1, n2] = q.front();
            q.pop();

            n1->val += n2->val;

            // LEFT
            if (n1->left && n2->left) {
                q.push({n1->left, n2->left});
            } else if (!n1->left) {
                n1->left = n2->left;
            }

            // RIGHT
            if (n1->right && n2->right) {
                q.push({n1->right, n2->right});
            } else if (!n1->right) {
                n1->right = n2->right;
            }
        }

        return root1;
    }
};
*/

int main()
{
    
}