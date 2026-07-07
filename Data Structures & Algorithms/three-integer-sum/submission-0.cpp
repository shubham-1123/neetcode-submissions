class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result ;
        set<vector<int>> st;

        if(nums.size() < 3) 
            return result ;
        sort(nums.begin(), nums.end());

        for(int i=0;i<nums.size();i++){
            int left= i+1, right = nums.size()-1;
            while(left < right){
                int sum = nums[i] + nums[left] + nums[right] ;
                if(sum > 0){
                    right -- ;
                }
                else if(sum < 0){
                    left ++;
                }
                else{
                    vector<int> v;
                    v.push_back(nums[i]);
                    v.push_back(nums[left]);
                    v.push_back(nums[right]);
                    sort(v.begin(), v.end());
                    st.insert(v);

                    while(left<right && nums[left]==nums[left+1])
                        left ++ ;
                    while(left < right && nums[right] == nums[right-1])
                        right --;
                    left ++ ;
                    right --;
                }

            }
        }

        for(auto x: st){
            result.push_back(x);
        }

        return result ;
    }
};
