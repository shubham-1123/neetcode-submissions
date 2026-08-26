class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 0;
        for(auto x: nums){
            if(index < 2 || x != nums[index-2])
                nums[index++] = x;
        }
        return index;
    }
};