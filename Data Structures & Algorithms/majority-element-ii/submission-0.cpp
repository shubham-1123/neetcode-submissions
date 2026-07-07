class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if(nums.size() < 2)
            return nums;
        
        int first = -1, second = -1;
        int count1 = 0, count2 = 0;

        for(int i=0;i<nums.size();i++){
            if(nums[i] == first){
                count1 ++;
            }
            else if(nums[i] == second){
                count2 ++;
            }
            else if(count1 == 0){
                first = nums[i];
                count1 = 1;
            }
            else if(count2 == 0){
                second = nums[i];
                count2 = 1;
            }
            else {
                count1 --;
                count2 --;
            }
        }

        count1 = 0, count2 = 0;

        for(int i=0;i<nums.size();i++){
            if(nums[i] == first)
                count1++;
            else if(nums[i] == second)
                count2++;
        }
        vector<int> elements;
        if(count1 > nums.size()/3)
            elements.push_back(first);
        if(count2 > nums.size()/3)
            elements.push_back(second);
        return elements;
    }
};