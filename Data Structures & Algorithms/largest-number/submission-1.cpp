class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int x, int y){
            string ab = to_string(x) + to_string(y);
            string ba = to_string(y) + to_string(x);
            return (ab > ba);
        });
        if(nums[0] == 0){
            return "0";
        }
        string result= "";
        for(auto x: nums){
            result += to_string(x);
        }

        return result;
    }
};