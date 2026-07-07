class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result = {{}};
        if(nums.size() == 1){
            result.push_back(nums);
            return result;
        }
        vector<int> arr;
        for(int i=0; i<nums.size(); i++){
            int n = result.size();
            for(int j=0;j<n;j++){
                arr = result[j];
                arr.push_back(nums[i]);
                result.push_back(arr);
            }
        }
        return result ;
    }
};
