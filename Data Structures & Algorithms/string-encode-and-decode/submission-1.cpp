class Solution {
public:

    string encode(vector<string>& strs) {
        string encodedString = "";
        if(strs.size() == 0)
            return "";
        for(int i=0;i<strs.size();i++){
            encodedString += to_string(strs[i].size()) + '#' + strs[i];
        }
        return encodedString;
    }

    vector<string> decode(string s) {
        vector<string> decodedString;
        int i = 0; 
        string temp = "";
        while(i < s.size()){
            int len = 0;
            while(i < s.size() && s[i] != '#'){
                len = len*10 + s[i]-'0';
                i ++ ;
            }
            i ++;
            len = i + len;
            while(i < len){
                temp += s[i];
                i ++;
            }
            decodedString.push_back(temp);
            temp = "";
        }
        return decodedString;
    }
};
