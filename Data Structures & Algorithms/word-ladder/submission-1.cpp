class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        if(!st.count(endWord)) return 0;
        
        queue<string> q;
        unordered_set<string> visited;

        q.push(beginWord);
        int length = 0;
        while(!q.empty()){
            int n = q.size();
            length +=1;
            for(int i=0;i<n;i++){
                string word = q.front();
                q.pop();
                if(word == endWord)
                    return length;
                if(visited.count(word))continue;
                visited.insert(word);
                for(int j=0;j<word.size();j++){
                    string str = word;
                    for(int k='a';k<='z';k++){
                        str[j] = static_cast<char>(k);
                        if(st.count(str) && !visited.count(str))
                            q.push(str);
                    }
                }
            }
        }
        return 0;
    }
};
