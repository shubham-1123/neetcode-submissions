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
    unordered_map<int,int> order;
public:
    TreeNode* helper(vector<int>& postorder, int& start, int left, int right){
        if(left > right)return nullptr;
        int val = postorder[start--];
        TreeNode* root = new TreeNode(val);
        if(left == right)return root;
        int index = order[val];
        root->right = helper(postorder, start, index+1, right);
        root->left = helper(postorder, start, left, index-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 1){
            TreeNode* root = new TreeNode(inorder[0]);
            return root;
        }
        for(int i=0;i<inorder.size();i++){
            order[inorder[i]] = i;
        }
        int start = postorder.size()-1;
        return helper(postorder, start, 0, start);
    }
};