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
    bool isValidBST(TreeNode* root) {
        if(!root->left && !root->right) return true;
        int left = INT_MIN, right = INT_MAX;
        return validate(root, left, right);
    }
    bool validate(TreeNode* root, int left, int right){
        if(root == nullptr)return true;
        if((root->val > left) && (root->val < right)){
            return validate(root->left, left, root->val) && validate(root->right, root->val, right);
        }
        return false;
    }
};
