class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLen = INT_MAX;
        int i=0, j=0, sumSofar = 0;

        while(j < nums.size()){
            sumSofar += nums[j];
            while(sumSofar >= target){
                minLen = min(minLen, j-i+1);
                sumSofar -= nums[i++];
            }
            j ++;
        }
        return (minLen == INT_MAX)?0:minLen;
    }
};