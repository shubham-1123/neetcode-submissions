class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int length = 0, counter = 0;
        int i = 0, j = 0;
        while(i < nums.size()){
            if(nums[i]){
                length = max(length, i-j+1);
                i++;
            }else if(counter!=k){
                length = max(length, i-j+1);
                // std::cout<<"h1 " << length << '\n';
                counter ++, i++;
            }else{
                if(nums[j] == 0)
                    counter --;
                j ++;
            }
        }
        return length;
    }
};