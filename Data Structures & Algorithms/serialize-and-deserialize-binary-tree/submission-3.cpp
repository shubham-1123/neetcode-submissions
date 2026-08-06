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

class Codec {
public:
    void helper(TreeNode* root, string& str){
        if(!root){
            str+= "null,";
            return;
        }
        str+= to_string(root->val) + ',';
        helper(root->left, str);
        helper(root->right, str);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str = "";
        helper(root, str);
        return str;
    }

    TreeNode* createBT(queue<string>& q){
        if(q.empty()) return nullptr;
        string src = q.front();
        q.pop();
        if(src == "null")return nullptr;
        TreeNode* root = new TreeNode(stoi(src));
        root->left = createBT(q);
        root->right = createBT(q);
        return root; 
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q;
        string temp = "";
        for(char x : data){
            if(x == ','){
                q.push(temp);
                temp = "";
            }else{
                temp += x;
            }
        }
        return createBT(q);
    }
};






