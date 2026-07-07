class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n, -1);
        vector<int> right(n, n);
        stack<int> st;

        for(int i=0;i<n;i++){
            while(!st.empty()){
                if(heights[st.top()] >= heights[i]){
                    st.pop();
                }else{
                    left[i] = st.top();
                    break;
                }
            }
            st.push(i);
        }

        while(!st.empty())
            st.pop();
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty()){
                if(heights[st.top()] >= heights[i]){
                    st.pop();
                }else{
                    right[i] = st.top();
                    break;
                }
            }
            st.push(i);
        }
        int area = 0;

        for(int i=0;i<n;i++){
            left[i]+=1;
            right[i]-=1;
            area = max(area, heights[i]*(right[i]-left[i]+1));
        }
        return area;
    }
};
