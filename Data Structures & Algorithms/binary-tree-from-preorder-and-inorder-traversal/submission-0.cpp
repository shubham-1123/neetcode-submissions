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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 1) {
            TreeNode* root = new TreeNode(preorder[0]) ;
            return root ;
        }
        map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]] = i ;
        }
        int start = 0;
        return makeBT(preorder, mp, start, 0, preorder.size()-1) ;
    }
    TreeNode* makeBT(vector<int>& preorder, map<int,int>& mp, int& start, int left, int right){
        if(left > right)return nullptr ;
        int val = preorder[start] ;
        start ++ ;
        int index = mp[val] ;
        TreeNode* root = new TreeNode(val) ;
        if(left == right)return root ;
        root->left = makeBT(preorder, mp, start, left, index-1) ;
        root->right = makeBT(preorder, mp, start, index+1, right) ;
        return root ;
    }   
};
