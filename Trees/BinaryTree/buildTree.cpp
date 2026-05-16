#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include<unordered_map>

using namespace std;

/*
105. Construct Binary Tree from Preorder and Inorder Traversal

https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

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
    int idx = 0;
    unordered_map<int, int> mp;
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int n=inorder.size();

        for (int i = 0; i < n; i++)
        {
           mp[inorder[i]]=i;
        }

        return build(preorder,0,n-1);
        
    }
    TreeNode *build(vector<int> &preorder, int left,int right)
    {
        if(left>right) return nullptr;

        int rootVal=preorder[idx++];

        TreeNode *root=new TreeNode(rootVal);
        
        // root pos  in inorder
        int mid=mp[rootVal];

        root->left=build(preorder,left,mid-1);
        root->right=build(preorder,mid+1,right);

        return root;


    }
};

int main()
{
}