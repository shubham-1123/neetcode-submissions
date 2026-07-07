class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> order(wordList.begin(), wordList.end());
        if(!order.count(endWord))return 0;
        int ladderLen = 1;

        queue<string>q;
        q.push(beginWord);
        unordered_set<string> visited;

        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                beginWord = q.front();
                q.pop();
                
                if(beginWord == endWord) return ladderLen;
                if(visited.count(beginWord))continue;
                visited.insert(beginWord);

                for(int j=0;j<beginWord.size();j++){
                    for(int k='a';k<='z';k++){
                        string word = beginWord;
                        word[j] = static_cast<char>(k);
                        if(order.count(word) && !visited.count(word)){
                            q.push(word);
                        }
                    }
                }

            }
            ladderLen++;
        }
        return 0;
    }
};
