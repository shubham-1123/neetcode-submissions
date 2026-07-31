class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()== 1) return 0;
        int jmp = 0, temp = 0, counter = 0;

        for(int i=0;i<nums.size()-1;i++){
            jmp = max(jmp, i+ nums[i]);
            if(i == temp){
                temp = jmp;
                counter++;
            }
        }
        return counter;
    }
};



// class Solution {
// public:
//     int jump(vector<int>& nums) {
//         if(nums.size() == 1) return 0;
//         int jmp = nums[0], temp = nums[0];
//         int count = 0;
//         for(int i=1;i<nums.size();i++){
//             jmp = max(jmp, nums[i]+i);
//             if(i == temp){
//                 temp = jmp;
//                 count ++;
//             }
//         }
//         return count;
//     }
// };