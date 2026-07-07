class Solution {
public:
    bool isValid(string s) {
        if(s.size() == 1)return false;
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i] == '{' || s[i] == '[' || s[i] == '('){
                st.push(s[i]);
            }
            if(st.empty())return false;

            char x = s[i];

            switch(x){
                case '}' : if(st.top() != '{') return false;
                           st.pop(); 
                           break;
                case ']' : if(st.top() != '[') return false;
                           st.pop();
                           break;
                case ')' : if(st.top() != '(') return false;
                           st.pop();
                           break;
                default:   break;
            }
        }
        return (st.empty())?true:false;
    }
};
