class Solution {
public:
    bool isValid(string s) {
        if(s.size() == 1)return false;
        stack<char> st ;
        for(char x: s){
            if(x == '{' or x == '[' or x == '('){
                st.push(x);
                continue;
            }
            if(st.empty()) return false;
            if(x == '}'){
                char c = st.top();
                if(c != '{') return false;
                st.pop();
            }
            else if(x == ']'){
                char c = st.top();
                if(c != '[') return false;
                st.pop();
            }
            else if(x == ')'){
                char c = st.top();
                if(c != '(') return false;
                st.pop();
            }
        }
        return (st.empty())? true:false;
    }
};
