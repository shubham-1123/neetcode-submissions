class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size()) return "";
        string result = "";

        vector<int> t_count(256, 0);
        vector<int> aux(256, 0);
        for(auto x: t)
            t_count[x]++;
        
        int left = 0, right = 0;
        int length = INT_MAX;

        auto isValid = [&](const vector<int>& aux){
            for(int i=0;i<256;i++){
                if(t_count[i] > 0 && (aux[i] < t_count[i]))
                    return false;
            }
            return true;
        };

        while(right < s.size()){
            aux[s[right]] ++ ;
            if(isValid(aux)){
                while(isValid(aux)){
                    if(right-left+1 < length){
                        length = right-left+1;
                        result = s.substr(left, length); 
                    }
                    aux[s[left]]--;
                    left ++;
                }
            }
            right++;
        }
        return result;
    }
};
