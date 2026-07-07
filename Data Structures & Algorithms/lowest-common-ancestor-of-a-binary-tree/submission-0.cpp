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
    unordered_map<TreeNode*, pair<TreeNode*,int>> info;
public:
    void helper(TreeNode* root, TreeNode* parent, int level){
        if(root){
            info[root] = {parent, level};
            helper(root->left, root, level+1);
            helper(root->right, root, level+1);
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        info.clear();
        helper(root, root, 0);

        auto p1 = info[p], q1 = info[q];

        TreeNode* first = p, *second = q;

        int d1 = p1.second, d2 = q1.second;

        if(d1 < d2){
            swap(first, second);
        }
        int diff = abs(d1-d2);

        while(diff!=0){
            diff --;
            first = info[first].first;
        }
        if(first == second) return first;

        while(first != second){
            first = info[first].first;
            second = info[second].first;
        }

        return first;
    }
};