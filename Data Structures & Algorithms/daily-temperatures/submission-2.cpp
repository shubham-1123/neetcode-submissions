class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size() ;
        vector<int> result(n,0);

        stack<int> st ;

        for(int i=n-1;i>=0;i--){
            while(!st.empty()){
                if(temp[st.top()] <= temp[i]){
                    st.pop();
                }else{
                    result[i] = (st.top()-i);
                    break;
                }
            }
            st.push(i);
        }
        return result;
    }
};
