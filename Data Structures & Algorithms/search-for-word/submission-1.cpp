class Solution {
public:
    bool helper(vector<vector<char>>& grid, int i, int j, int k, string& word){
        if(k >= word.size()) return true;
        if(i<0||i>=grid.size()||j<0||j>=grid[0].size()||grid[i][j]!=word[k])return false;
        char x  = grid[i][j];
        grid[i][j] = '*';
        bool ans = helper(grid, i+1, j, k+1, word) || helper(grid, i-1, j, k+1, word) || helper(grid, i, j+1, k+1, word) || helper(grid, i, j-1, k+1, word);
        grid[i][j] = x;
        return ans;
    }
    bool exist(vector<vector<char>>& grid, string word) {
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == word[0]){
                    if(helper(grid, i, j, 0, word))
                        return true;
                }
            }
        }
        return false;
    }
};
