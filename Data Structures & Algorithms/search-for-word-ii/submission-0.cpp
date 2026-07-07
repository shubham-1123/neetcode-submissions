// class Solution {
// public:
//     vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
//     }
// };

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
    ~TrieImpl() = default;
};

class Solution {
    unordered_set<string> res;
    vector<vector<bool>> visited;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        res.clear();
        visited.resize(board.size(),  vector<bool>(board[0].size(), false));

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
        if(i<0||i>=board.size()||j<0||j>=board[0].size() || visited[i][j] || (curr->children[board[i][j]-'a'] == nullptr))
            return;
        
        visited[i][j] = true ;
        curr = curr->children[board[i][j]-'a'];
        str += board[i][j];
    
        if(curr->endshere){
            res.insert(str);
            curr->endshere = false;
        }
        dfs(board, i+1, j, curr, str);
        dfs(board, i-1, j, curr, str);
        dfs(board, i, j+1, curr, str);
        dfs(board, i, j-1, curr, str);

        visited[i][j] = false;
    }
};