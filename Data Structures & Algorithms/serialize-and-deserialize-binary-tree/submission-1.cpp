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
    void makeString(TreeNode* root, string& str){
        if(root == nullptr){
            str+="null,";
            return;
        }
        str += to_string(root->val)+',';
        makeString(root->left, str);
        makeString(root->right, str);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str = "";
        makeString(root, str);
        return str;
    }
    TreeNode* buildTree(queue<string>& q){
        string str = q.front();
        q.pop() ;
        if(str == "null") return nullptr;
        TreeNode* root = new TreeNode(stoi(str));
        root->left = buildTree(q);
        root->right = buildTree(q);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q;
        string str = "";
        for(char x : data){
            if(x == ','){
                q.push(str);
                str = "";
            }else{
                str += x;
            }
        }
        return buildTree(q);
    }
};












