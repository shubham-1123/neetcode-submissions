class Solution {
    int count ;
public:
    bool isValid(vector<string>& curr, int row, int col){
        for(int i=0;i<curr.size();i++){
            if(curr[i][col] =='Q')return false;
            if(row-i>=0 && col-i>=0 && curr[row-i][col-i] == 'Q')return false;
            if(row-i>=0 && col+i<curr.size() && curr[row-i][col+i]=='Q')return false;
        }
        return true;
    }
    void helper(vector<string>& curr, int row){
        if(row >= curr.size()){
            count ++;
            return;
        }
        for(int i=0;i<curr.size();i++){
            if(isValid(curr, row, i)){
                curr[row][i] = 'Q';
                helper(curr, row+1);
                curr[row][i] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        count = 0;
        vector<string> curr(n, string(n, '.'));
        helper(curr, 0);
        return count;
    }
};