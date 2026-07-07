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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 1){
            TreeNode* root = new TreeNode(preorder[0]);
            return root;
        }
        mp.clear();

        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }
        int start = 0;
        return helper(preorder, start, 0, preorder.size()-1);
    }
    TreeNode* helper(vector<int>& preorder, int& start, int l, int r){
        if(l > r) return nullptr;
        int val = preorder[start++];
        TreeNode* root = new TreeNode(val);
        if(l == r) return root;
        int index = mp[val];
        root->left = helper(preorder, start, l, index-1);
        root->right = helper(preorder, start, index+1, r);
        return root;
    }
};
