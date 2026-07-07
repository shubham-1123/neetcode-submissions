class Solution {
public:
    vector<vector<string>> result;
    bool isPalindrome (const string& str, int i, int j){
        while(i < j){
            if(str[i] != str[j])return false;
            i ++, j--;
        }
        return true;
    };
    vector<vector<string>> partition(string s) {
        result.clear();
        solve(s, 0, {});
        return result;
    }
    void solve(string& str, int i, vector<string> temp){
        if(i >= str.size()){
            result.push_back(temp);
            return;
        }
        string st = "";
        for(int index=i;index<str.size();index++){
            st += str[index];
            if(isPalindrome(str, i, index)){
                temp.push_back(st);
                solve(str, index+1, temp);
                temp.pop_back();
            }
        }
    }
};
