class Solution {
public:
    bool binarySearch(vector<int>& weights, int mid, int days){
        int count = 0;
        int sum = 0;
        for(int i=0;i<weights.size();i++){
            sum += weights[i];
            if(sum > mid){
                sum = weights[i];
                count ++;
            }
        }
        if(sum <= mid)
            count ++;
        return (count <= days);
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);
        if(days == 1)
            return right;
        int ans = 0;
        while(left <= right){
            int mid = (left + right)/2 ;
            if(binarySearch(weights, mid, days)){
                ans = mid;
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        return ans;
    }
};