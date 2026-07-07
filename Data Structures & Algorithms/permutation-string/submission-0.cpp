class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        string temp = "";
        int i=0;

        sort(s1.begin(), s1.end());

        while(i < s1.size()){
            temp.push_back(s2[i]);
            i ++;
        }
        string str = temp ;
        sort(str.begin(), str.end());
        if(s1 == str)return true;

        while(i < s2.size()){
            temp.erase(temp.begin());
            temp.push_back(s2[i]);
            str = temp;
            sort(str.begin(), str.end());
            if(str == s1) return true;
            i ++ ;
        }
        return false;
    }
};

