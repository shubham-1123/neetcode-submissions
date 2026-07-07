class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = *max_element(piles.begin(), piles.end());

        auto check = [&](int mid){
            int count = 0;
            for(int i=0;i<piles.size();i++){
                if(piles[i] <= mid){
                    count += 1;
                }else{
                    int d = piles[i]/mid;
                    int mod = piles[i]%mid;
                    if(mod > 0)
                        d = d + 1;
                    count += d;
                }
            }
            return (count <= h);
        };

        int ans = 0;
        while(left <= right){
            int mid = left + (right-left)/2;
            if(check(mid)){
                ans = mid;
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        return ans;
    }
};
