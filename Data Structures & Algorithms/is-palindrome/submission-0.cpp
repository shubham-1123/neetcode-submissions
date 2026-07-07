class Solution {
public:
    bool isPalindrome(string s) {
        int l =0, r = s.size()-1;
        while(l < r){
            while(l < r && !isAlphaNum(s[l]))
                l ++;
            while(l < r && !isAlphaNum(s[r]))
                r --;
            if(tolower(s[l]) != tolower(s[r]))
                return false;
            l ++;
            r --;
        }
        return true;
    }
    bool isAlphaNum(char x){
        return (x >= 'A' && x <= 'Z' || x >= 'a' && x <= 'z' || x >= '0' && x <= '9') ;
    }
};
