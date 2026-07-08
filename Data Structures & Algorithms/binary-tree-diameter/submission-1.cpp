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
        if(root == nullptr)return 0;
        int left = helper(root->left, diameter);
        int right = helper(root->right, diameter);
        int temp = max(left+right+1, max(left, right)+1);
        diameter = max(diameter, temp);
        return max(left, right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = INT_MIN;
        helper(root, diameter);
        return diameter-1;
    }
};
