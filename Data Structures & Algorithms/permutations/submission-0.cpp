class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> permute(vector<int>& nums) {
        result.clear();
        solve(nums, 0);
        return result;
    }
    void solve(vector<int>& nums, int i){
        if(i >= nums.size()){
            result.push_back(nums);
            return;
        }

        for(int j=i;j<nums.size();j++){
            swap(nums[i], nums[j]);
            solve(nums, i+1);
            swap(nums[i], nums[j]);
        }
    }
};
