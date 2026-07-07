class Solution {
public:
    char findTheDifference(string s, string t) {
        int i = 0, j=0;
        int xor_val = 0;
        while(i < s.size() && j < t.size()){
            xor_val ^= (static_cast<int>(s[i])^static_cast<int>(t[j]));
            i ++, j++;
        }
        if(i<s.size()){
            xor_val^= static_cast<int>(s[i]);
        }
        if(j<t.size()){
            xor_val^= static_cast<int>(t[j]);
        }
        return static_cast<char>(xor_val);
    }
};