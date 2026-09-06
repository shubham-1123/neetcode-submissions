class Solution {
public:
    void helper(int n, int open, int close, string st, vector<string>& result){
        if(close + open > 2*n)return;
        if(open == close && (open+close == 2*n)){
            result.push_back(st);
            return;
        }
        if(open < n  && (open == 0 || open >= close))
            helper(n, open+1, close, st+'(', result);
        if(close < n && close < open)
            helper(n, open, close+1, st+')', result);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if(n == 1){
            string st = "()";
            result.push_back(st);
            return result;
        }
        helper(n, 0, 0, "", result);
        return result;
    }
};




// class Solution {
// public:
//     void helper(int n, int open, int close, string st, vector<string>& result){
//         if(close + open > 2*n)return;
//         if(open + close == 2*n){
//             result.push_back(st);
//             return;
//         }
//         if(open < n)
//             helper(n, open+1, close, st+'(', result);
//         if(close < open)
//             helper(n, open, close+1, st+')', result);
//     }
//     vector<string> generateParenthesis(int n) {
//         vector<string> result;
//         helper(n, 0, 0, "", result);
//         return result;
//     }
// };

