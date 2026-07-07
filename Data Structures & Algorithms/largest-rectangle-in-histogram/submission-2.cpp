class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size() ;
        vector<int> left(n, -1);
        vector<int> right(n, n);
        stack<int> st;

        for(int i=0;i<n;i++){
            while(!st.empty()){
                if(heights[st.top()] >= heights[i])
                    st.pop();
                else {
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
                if(heights[st.top()]>= heights[i]){
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
            left[i] ++;
            right[i] --;
            area = max(area, heights[i]*(right[i]-left[i]+1));
        }
        return area;

        // for(auto x: left)
        //     cout << x << " ";
        // cout << '\n';
        // for(auto x: right)
        //     cout << x << " ";
        // cout << endl;
        // return 1;
    }
};
// Input: heights = [7,1,7,2,2,4]

// Output: 8

// Input: heights = [2,1,5,6,2,3]
// Output: 10

