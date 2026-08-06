/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int helper(Node* root, int& length){
        if(!root) return 0;
        int max1=0, max2=0;
        for(auto &x : root->children){
            int h = helper(x, length) + 1;
            if(h > max1){
                max2 = max1;
                max1 = h;
            }else if(h > max2){
                max2 = h;
            }
        }
        length = max(length, max1+max2);
        return max1;
    }
    int diameter(Node* root) {
        if(root->children.size() == 0)return 0;
        int length = 0;
        helper(root, length);
        return length;
    }
};
