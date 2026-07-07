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
    int maxPathSum(TreeNode* root) {
        if(!root->left && !root->right) 
            return root->val;
        int maxVal = INT_MIN ;
        helper(root, maxVal);
        return maxVal;
    }
    int helper(TreeNode* root, int& maxVal){
        if(!root) return 0;

        int left = helper(root->left, maxVal);
        int right = helper(root->right, maxVal);

        int temp1 = max(max(left, right) + root->val , root->val);
        int temp2 = max(temp1, left+right+root->val);
        maxVal = max(maxVal, temp2);
        return temp1;
    }
};
