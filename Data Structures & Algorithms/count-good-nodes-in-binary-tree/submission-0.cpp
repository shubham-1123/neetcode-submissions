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
    int goodNodes(TreeNode* root) {
        return solve(root, root->val);
    }
    int solve(TreeNode* root, int maxVal){
        if(root == nullptr)return 0;

        int res = (root->val >= maxVal)?1:0;
        maxVal = max(maxVal, root->val);
        res+= solve(root->left, maxVal);
        res+= solve(root->right, maxVal);
        return res;
    }
};
