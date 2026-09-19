class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        set<vector<int>> st;
        vector<vector<int>> ans;
        vector<int> v ;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                int left = j+1, right = nums.size()-1;   
                while(left < right){
                    v.clear();
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    if(sum > target) right --;
                    else if(sum < target) left ++;
                    else {
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[left]);
                        v.push_back(nums[right]);
                        sort(v.begin(), v.end());
                        st.insert(v); 

                        while(left < right && nums[left]==nums[left+1])
                            left ++;
                        while(left < right && nums[right-1]==nums[right])
                            right --;
                        left ++, right --;
                    }
                }
            }
        }
        for(auto x: st)
            ans.push_back((x));
        return ans;
    }
};