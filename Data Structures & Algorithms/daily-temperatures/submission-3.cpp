class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> temp(temperatures.size(), 0);
        stack<int> st;

        for(int i=temperatures.size()-1;i>=0;i--){
            while(!st.empty()){
                if(temperatures[st.top()] <= temperatures[i]){
                    st.pop();
                }else{
                    temp[i] = st.top()-i;
                    break;
                }
            }
            st.push(i);
        }
        return temp;
    }
};
