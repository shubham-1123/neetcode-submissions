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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> order;
        if(!root) return order;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        map<int, vector<int>> mp;
        while(!q.empty()){
            auto [root, d] = q.front();q.pop();
            mp[d].push_back(root->val);
            if(root->left)
                q.push({root->left, d-1});
            if(root->right)
                q.push({root->right, d+1});
        }
        for(auto &x: mp){
            order.push_back(x.second);
        }
        return order;
    }
};