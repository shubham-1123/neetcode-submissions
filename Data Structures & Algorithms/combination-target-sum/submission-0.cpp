class Solution {
public:
    vector<vector<int>> result;
    void solve(vector<int>& nums, int target, int i, int sum, vector<int> curr){
        if(i > nums.size())return;
        if(sum > target) return;
        if(sum == target){
            result.push_back(curr);
            return;
        }

        for(int index=i;index<nums.size();index++){
            curr.push_back(nums[index]);
            solve(nums, target, index, sum+nums[index], curr);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        result.clear();
        // sort(nums.begin(), nums.end());
        
        solve(nums, target, 0, 0, {});
        return result;
    }
};
