class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1){
            return (nums[0]%k == 0)?1:0;
        }
        unordered_map<int,int> mp;
        mp[0] = 1;
        int curr_sum=0, counter=0;
        for(int i=0;i<nums.size();i++){
            curr_sum+=nums[i];
            if(mp.count(curr_sum%k)){
                counter += mp[curr_sum%k];
            }
            mp[curr_sum%k] ++;
        }
        return counter;
    }
};