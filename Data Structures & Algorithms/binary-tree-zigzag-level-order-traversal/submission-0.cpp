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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> traversal;
        if(root == nullptr)return traversal;
        if(!root->left && !root->right){
            traversal.push_back({root->val});
            return traversal;
        }
        queue<TreeNode*> q;
        q.push(root);
        int level =  0;

        while(!q.empty()){
            int n = q.size();
            vector<int> v ;
            for(int i=0;i<n;i++){
                root = q.front();
                q.pop();
                if(level%2)
                    v.insert(v.begin(), root->val);
                else
                    v.push_back(root->val);
                if(root->left)
                    q.push(root->left);
                if(root->right)
                    q.push(root->right);   
                
            }
            traversal.push_back(v);
            level ++;
        }
        return traversal;
    }
};