#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include<unordered_map>
#include<climits>
using namespace std;

/*
98. Validate Binary Search Tree
https://leetcode.com/problems/validate-binary-search-tree/description/

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

class Solution {
public:
    bool isValidBST(TreeNode* root) 
    {   

        return validate(root,LLONG_MIN,LLONG_MAX);

        
    }

    bool validate(TreeNode *root,long long low, long long high)
    {
        if(!root) return true;
        
        // curr node must lie between range 
        if(root->val<=low || root->val>=high) return false;
        
        return validate(root,low,root->val) && validate(root,root->val,high);

    }
};

int main()
{
}