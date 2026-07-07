class Solution {
public:
    vector<string> result;
    vector<string> generateParenthesis(int n) {
        result.clear();
        solve("", 0, 0, n);
        return result;
    }
    void solve(string str, int open, int close, int n){
        if(open+close > 2*n)return;
        if(open+close == 2*n){
            result.push_back(str);
            return;
        }
        if(open < n)
            solve(str+'(', open+1, close, n);
        if(close < open)
            solve(str+')', open, close+1, n);
    }
};
