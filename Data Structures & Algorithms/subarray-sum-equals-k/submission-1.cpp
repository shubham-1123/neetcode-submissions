class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int current_sum = 0, count = 0;
        mp[0] = 1;
        for(int i=0;i<nums.size();i++){
            current_sum += nums[i];
            if(mp.count(current_sum - k)){
                count += mp[current_sum-k];
            }
            mp[current_sum]++;
        }
        return count ;
    }
};