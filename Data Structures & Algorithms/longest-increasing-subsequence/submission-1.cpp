class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() <= 1)return nums.size();
        vector<int> aux;
        aux.push_back(nums[0]);

        for(int i=1;i<nums.size();i++){
            if(aux.back() < nums[i]){
                aux.push_back(nums[i]);
            }else{
                int index = lower_bound(aux.begin(), aux.end(), nums[i]) - aux.begin();
                aux[index] = nums[i];
            }
        }
        for(auto x: aux)
            std::cout << x << " ";
        std::cout << '\n';
        return aux.size();
    }
};
