/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int helper(TreeNode* root, int& diameter){
        if(!root) return 0;
        int left = helper(root->left, diameter);
        int right = helper(root->right, diameter);
        int temp1 = max(max(left, right)+1, 1);
        int temp2 = max(temp1, left+right+1);
        diameter = max(temp2, diameter);
        return temp1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root->left && !root->right) return 0;
        int diameter = INT_MIN;
        helper(root, diameter);
        return diameter-1;
    }
};
