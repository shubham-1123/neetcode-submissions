class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size();
        sort(s1.begin(), s1.end());

        string temp = "";
        int i=0;
        temp = s2.substr(0, m);
        sort(temp.begin(), temp.end());
        if(s1 == temp)return true;

        i = 1;

        while(i < s2.size()){
            temp.erase(temp.begin());
            temp.push_back(s2[i]);
            string str = temp;
            sort(str.begin(), str.end());
            if(str == s1) return true;
            i ++ ;
        }
        return false;
    }
};

