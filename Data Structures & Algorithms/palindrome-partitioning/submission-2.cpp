class Solution {
    vector<vector<string>> result;
public:
    bool isPalindrome(string& st, int i, int j){
        while(i < j){
            if(st[i] != st[j]) return false;
            i ++, j --;
        }
        return true;
    }
    void helper(string& str, int i, vector<string> temp){
        if(i >= str.size()){
            result.push_back(temp);
            return;
        }
        string st = "";
        for(int index=i;index<str.size();index++){
            st += str[index];
            if(isPalindrome(str, i , index)){
                temp.push_back(st);
                helper(str, index+1, temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        result.clear();
        helper(s, 0, {});
        return result;
    }
};
