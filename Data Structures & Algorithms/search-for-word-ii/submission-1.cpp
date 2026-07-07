class TrieNode{
public:
    bool endshere;
    TrieNode* children[26];
    TrieNode(){
        endshere = false;
        for(int i=0;i<26;i++){
            children[i] = nullptr;
        }
    }
    ~TrieNode() = default;
};
class TrieImpl{
    TrieNode* root;
public:
    TrieImpl(TrieNode* root){
        this->root = root;
    }
    void insert(string word){
        TrieNode* curr = root;
        int idx; 
        for(int i=0;i<word.size();i++){
            idx = word[i]-'a';
            if(curr->children[idx] == nullptr){
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->endshere = true;
    }
    //  bool search(string word){
    //     TrieNode* curr = root ;
    //     int index;
    //     for(char x : word){
    //         index = x - 'a';
    //         if(curr->children[index] == nullptr)
    //             return false;
    //         curr = curr->children[index];
    //     }
    //     return curr->endshere;
    // }
    ~TrieImpl() = default;
};

class Solution {
    unordered_set<string> res;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        res.clear();

        TrieNode* root = new TrieNode();
        TrieImpl trie(root);

        for(int i=0; i<words.size(); i++){
            trie.insert(words[i]);
        }

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                dfs(board, i, j, root, "");
            }
        }
        return vector<string>(res.begin(), res.end());
    }
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* curr, string str){
        if(i<0||i>=board.size()||j<0||j>=board[0].size() || board[i][j] == '*' || (curr->children[board[i][j]-'a'] == nullptr))
            return;
    
        char temp = board[i][j] ;
        board[i][j] = '*';
        curr = curr->children[temp-'a'];
        str += temp;
        if(curr->endshere){
            res.insert(str);
            curr->endshere = false;
        }
        dfs(board, i+1, j, curr, str);
        dfs(board, i-1, j, curr, str);
        dfs(board, i, j+1, curr, str);
        dfs(board, i, j-1, curr, str);
        board[i][j] = temp;
    }
};