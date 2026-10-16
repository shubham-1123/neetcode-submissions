class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int currSum = 0;
        mp[0] = 1; 
        int counter = 0;
        for(int i=0;i<nums.size();i++){
            currSum += nums[i];
            if(mp.count(currSum-k)){
                counter += mp[currSum-k];
            }
            mp[currSum]++;
        }
        return counter;
    }
};