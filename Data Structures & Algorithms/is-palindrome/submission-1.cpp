class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        for(char x : s){
            if(x == ' ')
                continue;
            str += tolower(x);
        }
        str = regex_replace(str, regex("[^A-Za-z0-9]"), "");
        int left = 0, right = str.size()-1;

        while(left <= right){

            if(str[left] != str[right] )
                return false;
            left ++, right --;
        }
        return true;
    }
};


// regex pattern("^[A-Za-z0-9]+$");
// (regex_match(s, pattern)