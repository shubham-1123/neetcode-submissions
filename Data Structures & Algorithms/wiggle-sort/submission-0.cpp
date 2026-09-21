class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int i = 0, turn = 0;
        while(i < nums.size()-1){
            if(turn%2 == 0){
                if(nums[i] > nums[i+1])
                    swap(nums[i], nums[i+1]);
            }else {
                if(nums[i] < nums[i+1])
                    swap(nums[i], nums[i+1]);
            }
            turn = (turn+1);
            i ++ ;
        }
        // i = nums.size()-1, turn = 0;
        // while(i > 0){
        //     if(turn%2 == 0){
        //         if(nums[i] < nums[i-1])
        //             swap(nums[i], nums[i-1]);
        //     }else {

        //     }
        //     turn = (turn+1);
        //     i --;
        // }
    }
};
