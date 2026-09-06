class Solution {
    vector<vector<string>> result;
public:
    bool isValid(vector<string>& curr, int row, int col){
        
        for(int i=0;i<curr.size();i++){
            if(curr[i][col] == 'Q')return false;
            if(row-i>=0 && col-i>=0 && curr[row-i][col-i] =='Q') return false;
            if(row-i>=0 && col+i < curr.size() && curr[row-i][col+i] =='Q') return false;
        }
        return true;
    }
    void solve(vector<string>& curr, int row){
        if(row >= curr.size()){
            result.push_back(curr);
            return;
        }
        for(int i=0;i<curr.size();i++){
            if(isValid(curr, row, i)){
                curr[row][i] = 'Q';
                solve(curr, row+1);
                curr[row][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> curr(n , string(n, '.'));
        solve(curr, 0);
        return result;
    }
};


// class Solution {
//     vector<vector<string>> res ;
// public:
//     vector<vector<string>> solveNQueens(int n) {
        
//         vector<string> str(n , string(n , '.')) ;
//         solution(str , 0) ;

//         return res;

//     }
//     bool isValid(vector<string>& str , int row , int col){
         
         

//          for(int i=0;i<str.size();i++){
             
//              if(str[i][col] == 'Q' ) return false ;
//              if((row-i >= 0 && col-i >=0 ) && str[row-i][col-i] == 'Q') return false ;
//              if((row-i >= 0 && col+i < str.size()) && str[row-i][col+i] == 'Q') return false ;

//          }

//          return true;

//     }
//     void solution(vector<string>& str , int row) {
         
//          if(row >= str.size()){
//              res.push_back(str) ;
//              return  ;
//          }

//          for(int i=0;i<str.size();i++){
             
//              if(isValid(str , row , i)){
//                 str[row][i] = 'Q' ;
//                 solution(str , row + 1) ;
//                 str[row][i] = '.' ;
//              }

//          }

//     }
// };