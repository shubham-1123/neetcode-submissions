class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end()), right = accumulate(weights.begin(), weights.end(), 0);
        if(days  == 1) return right;
        auto helper = [&](int mid){
            int sum = 0, count = 0;
            for(int i=0;i<weights.size();i++){
                sum += weights[i];
                if(sum > mid){
                    count ++;
                    sum = weights[i];
                }
            }
            if(sum <= mid){
                count ++ ;
            }
            return (count <= days);
        }; 
        int mindays = 0;
        while(left <= right){
            int mid = left + (right-left)/2;
            // std::cout << mid <<  " ";
            if(helper(mid)){
                mindays = mid ;
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return mindays;
    }
};