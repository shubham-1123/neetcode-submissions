class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size())
            return "";
        
        vector<int> t_count(256, 0);
        auto isValid = [&](const vector<int>& t_count, const vector<int>& aux){
            for(int i=0;i<256;i++){
                if(t_count[i] > 0 && (aux[i] < t_count[i]))
                    return false;
            }
            return true;
        };
        for(auto x: t)
            t_count[x] ++;

        int left = 0, right = 0;
        int length = INT_MAX;
        string result = "";
        vector<int> aux(256, 0);
        while(right < s.size()){
            aux[s[right]] ++;
            if(isValid(t_count, aux)){
                while(isValid(t_count, aux)){
                    aux[s[left]]--;
                    left ++ ;
                }
                if(length > right-left+2){
                    length = (right-left+2);
                    result = s.substr(left-1, length);
                }
            }
            right ++ ;
        }
        return result;
    }
};