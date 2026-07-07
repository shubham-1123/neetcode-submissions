class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int value = 0;
        stack<int> st;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/"){
                int val = std::stoi(tokens[i]);
                st.push(val);
            }
            else{
                if(tokens[i] == "+"){
                    int a = st.top();
                    st.pop();
                    int b = st.top();
                    st.pop();
                    b = b + a;
                    st.push(b);
                }else if(tokens[i] == "-"){
                    int a = st.top();
                    st.pop();
                    int b = st.top();
                    st.pop();
                    b = b - a;
                    st.push(b);
                }else if(tokens[i] == "*"){
                    int a = st.top();
                    st.pop();
                    int b = st.top();
                    st.pop();
                    b = b * a;
                    st.push(b);
                }else if(tokens[i] == "/"){
                    int a = st.top();
                    st.pop();
                    int b = st.top();
                    st.pop();
                    b = b/a;
                    st.push(b);
                }
            }
        }
        return st.top();
    }
};
