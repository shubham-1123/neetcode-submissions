class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        auto cand = [](vector<int>& nums){
            int index=0, count=1, i=1;
            while(i < nums.size()){
                if(nums[i] == nums[index]){
                    count ++;
                }else{
                    count --;
                }
                if(count == 0){
                    count = 1;
                    index = i;
                }
                i ++;
            }
            return nums[index];
        };

        auto candidate = cand(nums);
        int count =0 ;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == candidate)
                count ++;
        }
        return (count > nums.size()/2)?candidate:-1;
    }
};