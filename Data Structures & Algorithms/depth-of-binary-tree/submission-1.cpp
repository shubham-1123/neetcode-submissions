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
    int helper(TreeNode* root, int& depth){
        if(!root)return 0;
        int left = helper(root->left, depth);
        int right = helper(root->right, depth);
        depth = max(depth, max(left,right)+1);
        return max(left, right)+1;
    }
    int maxDepth(TreeNode* root) {
        if(!root)return 0;
        if(!root->left && !root->right)return 1;
        int depth = INT_MIN;
        helper(root, depth);
        return depth;
    }
};
