class Solution {
public:
    bool solve(vector<int>& arr, long long int mid, int h){

        int count = 0;
        for(int i=0; i<arr.size(); i++){
            if(arr[i] <= mid){
                count ++;
            }else{
                int temp = arr[i]%mid ;
                count = count + (arr[i]/mid);
                if(temp)count ++;
            }
        }

        return (count <= h)?true:false;

    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long int sum = 0;
        for(auto x: piles)
            sum+=x;
        
        long long int left = 1, right= sum;
        long long int ans = 0;
        while(left <= right){
            long long int mid = left + (right-left)/2;
            if(solve(piles, mid, h)){
                ans = mid ;
                right = mid-1;
            }else{
                left = mid + 1;
            }
        }
        return (int)ans ;
    }
};
