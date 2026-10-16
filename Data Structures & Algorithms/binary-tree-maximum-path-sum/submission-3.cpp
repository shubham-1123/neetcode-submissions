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
    int solve(TreeNode* root, int& maxSum){
        if(!root)return 0;
        int left = solve(root->left, maxSum);
        int right = solve(root->right, maxSum);

        int temp1 = max(max(left, right) + root->val, root->val);
        int temp2 = max(temp1, root->val+left+right);
        maxSum = max(maxSum, temp2);
        return temp1; 
    }
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        solve(root, maxSum);
        return maxSum;
    }
};
