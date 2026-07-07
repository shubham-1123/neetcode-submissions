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
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        if(!root->left && !root->right) return true;
        bool flag = true;
        helper(root, flag) ;
        return flag;
    }
    int helper(TreeNode* root, bool& flag){
        if(root == nullptr) return 0 ;
        if(!root->left && !root->right) return 1 ;
        
        int leftHeight = helper(root->left, flag);
        int rightHeight = helper(root->right, flag);

        int diff = abs(leftHeight - rightHeight);
        if(diff > 1 && flag){
            flag = false;
        }
        return 1 + max(leftHeight, rightHeight) ;
    }

};
