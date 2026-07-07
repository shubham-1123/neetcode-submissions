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
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        solve(root, ans);
        return ans-1; 
    }
    int solve(TreeNode* root, int& ans){
        if(root == nullptr)return 0;

        int left = solve(root->left, ans);
        int right = solve(root->right, ans);

        int temp1 = max(max(left, right) + 1, 1);
        int temp2 = max(temp1, left+right+1) ;

        ans = max(ans, temp2) ;
        return temp1;

    }
};
