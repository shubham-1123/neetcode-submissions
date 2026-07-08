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
    vector<int> boundary;
    bool isLeaf(TreeNode* root){
        if(!root->left && !root->right)
            return true;
        return false;
    }
    void TraverseLeaf(TreeNode* root){
        if(root == nullptr) return; 
        if(isLeaf(root))
            boundary.push_back(root->val);
        TraverseLeaf(root->left);
        TraverseLeaf(root->right);
    }
    void TraverseLeft(TreeNode* root){
        if(root == nullptr || isLeaf(root)) return;
        
        boundary.push_back(root->val);
        if(root->left)    
            TraverseLeft(root->left);
        else
            TraverseLeft(root->right);
    }
    void TraverseRight(TreeNode* root){
        if(root == nullptr || isLeaf(root)) return;
        
        if(root->right)
            TraverseRight(root->right);
        else
            TraverseRight(root->left);
        boundary.push_back(root->val);
    }
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
         boundary.clear();
        if(!root->left && !root->right){
            boundary.push_back(root->val);
            return boundary;
        }
           
        boundary.push_back(root->val);

        TraverseLeft(root->left);
        TraverseLeaf(root);
        TraverseRight(root->right);

        return boundary;
    
    }
};
