class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        vector<int> arr;
        stack<int> st;
        int n = nums.size();

        for(int i=0;i<n;i++){
            while(!st.empty()){
                if((nums[i] > 0 && st.top() > 0) or (nums[i] < 0 and st.top() <0))
                    break;
                if(nums[i] < 0 && (abs(nums[i]) > st.top())){
                    st.pop();
                }else{
                    break;
                }
            }
            if(!st.empty() && (abs(nums[i]) == abs(st.top())) && (nums[i] < 0 && st.top() > 0)){
                st.pop();
                continue;
            }
            if(!st.empty() && (nums[i]< 0 && st.top() > 0) && (st.top() > abs(nums[i]))){
                continue;
            }
            st.push(nums[i]);
        }

        while(!st.empty()){
            arr.push_back(st.top());
            st.pop();
        }
        reverse(arr.begin(), arr.end());
        return arr;
    }
};