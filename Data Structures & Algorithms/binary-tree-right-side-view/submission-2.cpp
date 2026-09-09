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
    int level = 0;
public:
    void helper(TreeNode* root, unordered_map<int, int>& mp, int d){
        if(root){
            level = max(level, d);
            mp[d] = root->val;
            helper(root->left, mp, d+1);
            helper(root->right, mp, d+1);
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        if(!root)return {};
        vector<int> result;
        unordered_map<int, int> mp;
        helper(root, mp, 0);
        
        for(int i=0;i<=level;i++){
            result.push_back(mp[i]);
        }
        return result;
    }
};
