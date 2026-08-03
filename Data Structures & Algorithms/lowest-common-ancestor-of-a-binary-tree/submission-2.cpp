/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    unordered_map<TreeNode*, pair<TreeNode*, int>>mp;
public:
    void helper(TreeNode* root, TreeNode* parent, int level){
        if(root){
            mp[root] = {parent, level};
            helper(root->left, root, level+1);
            helper(root->right, root, level+1);
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        mp.clear();
        helper(root, root, 0);
        auto p1 = mp[p];
        auto q1 = mp[q];

        TreeNode* first = p, *second = q;
        int d1 = p1.second, d2 = q1.second;

        if(d2 > d1){
            swap(first, second);
        }
        int diff = abs(d1-d2);

        while(diff!=0){
            first = mp[first].first;
            diff --;
        }

        while(first != second){
            first = mp[first].first;
            second = mp[second].first;
        }
        return first;
    }
};