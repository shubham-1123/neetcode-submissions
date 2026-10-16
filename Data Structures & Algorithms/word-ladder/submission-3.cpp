class Solution {
    unordered_set<string> st;
    unordered_set<string> visited;
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        st.clear();
        visited.clear();

        st = unordered_set<string>(wordList.begin(), wordList.end());
        if(!st.count(endWord))return 0;

        queue<string> q;
        q.push(beginWord);
        
        int length = 0;

        while(!q.empty()){
            int n = q.size();
            length++;
            for(int i=0;i<n;i++){
                beginWord = q.front();
                q.pop();

                if(beginWord == endWord)
                   return length;
                if(visited.count(beginWord)) continue;
                visited.insert(beginWord);

                for(int j=0;j<beginWord.size();j++){
                    string word = beginWord;
                    for(int k='a';k<='z';k++){
                        word[j] = static_cast<char>(k);
                        if(st.count(word) && !visited.count(word)){
                            q.push(word);
                        }
                    }
                }
            }
        }
        return 0;
    }
};
