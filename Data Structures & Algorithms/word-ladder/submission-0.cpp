class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        if(st.find(endWord) == st.end()) return 0;

        unordered_set<string> visited;
        queue<string> q ;

        int len  = 1 ;
        q.push(beginWord);

        while(!q.empty()){
            int n = q.size() ;
            for(int i=0;i<n;i++){
                string word = q.front();
                q.pop();
                if(word == endWord)return len;
                for(int j=0;j<word.size();j++){
                    for(int k='a';k<='z';k++){
                        string str = word ;
                        str[j] = static_cast<char>(k);
                        if(st.find(str) != st.end() && visited.find(str) == visited.end()){
                            visited.insert(str);
                            q.push(str) ;
                        }
                    }
                }

            }
            len ++ ;
        }

        return 0;

    }
};
