class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size())return false;
        int i = 0;
        unordered_set<char> st(s1.begin(), s1.end());
        sort(s1.begin(), s1.end());
        while(i < s2.size()){
            if(st.count(s2[i])){
                string temp = s2.substr(i, s1.size());
                sort(temp.begin(), temp.end());
                if(temp == s1)return true;
            }
            i ++ ;
        }
        return false;

    }
};
