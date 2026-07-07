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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> view;
        map<int,int> mp;
        traverse(root, mp, 0);
        for(auto x: mp){
            view.push_back(x.second);
        }
        return view;
    }
    void traverse(TreeNode* root, map<int,int> &mp, int l){
        if(root){
            traverse(root->left, mp, l+1);
            mp[l] = root->val;
            traverse(root->right, mp, l+1);
        }
    }

};
