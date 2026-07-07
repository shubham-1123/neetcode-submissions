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
    TreeNode* find_Successor(TreeNode* root){
        while(root && root->left){
            root = root->left;
        }
        return root ;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return nullptr;

        if(key < root->val){
            root->left = deleteNode(root->left, key);
        }
        else if(key > root->val){
            root->right = deleteNode(root->right, key);
        }else{
            if(root->left == nullptr && root->right == nullptr){
                delete root ;
                return nullptr;
            }
            else if(!root->left or !root->right){
                TreeNode* temp = (root->left)?root->left:root->right;
                delete root ;
                return temp; 
            }
            else{
                TreeNode* successor = find_Successor(root->right);
                root->val = successor->val ;
                root->right = deleteNode(root->right, successor->val);
            }
        }

        return root ;

    }
};