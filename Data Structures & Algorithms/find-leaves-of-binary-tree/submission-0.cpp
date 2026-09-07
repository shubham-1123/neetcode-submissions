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
    vector<vector<int>>result;
public:
    int dfs(TreeNode* root){
        if(!root)return -1;
        int left = dfs(root->left);
        int right = dfs(root->right);

        int h = 1 + max(left, right);

        if(h >= result.size()){
            result.push_back({});
        }
        result[h].push_back(root->val);
        return h;
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        result.clear();
        dfs(root);
        return result;
    }
};
