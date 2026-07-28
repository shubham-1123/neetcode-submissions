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
    unordered_map<int,int> mp;
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        if(pre.size() == 1){
            TreeNode* root = new TreeNode(pre[0]);
            return root;
        }
        mp.clear();
        for(int i=0;i<in.size();i++){
            mp[in[i]] = i ;
        }
        int start = 0;
        return helper(pre, start, 0, in.size()-1);
    }
    TreeNode* helper(vector<int>& pre, int& start, int l, int r){
        if(l > r)return nullptr;
        int val = pre[start++];
        TreeNode* root = new TreeNode(val);
        if(l == r)return root;
        int index = mp[val];
        root->left = helper(pre, start, l, index-1);
        root->right = helper(pre, start, index+1, r);
        return root;
    }
};
