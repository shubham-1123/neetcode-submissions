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
        if(root->left == nullptr && root->right == nullptr)
            return true;
        return check(root, INT_MIN, INT_MAX) ;
    }
    bool check(TreeNode* root, int left, int right) {
        if(root == nullptr) return true ;

        if(root->val < right && root->val > left)
            return check(root->left, left, root->val) and check(root->right, root->val, right) ;
        else
            return false;
    }
};
