class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long mod = 1e9 + 7;
        long even = 1, odd = 0;
        long prefix =0, ans = 0;
        for(auto x: arr){
            prefix += x ;
            if(prefix%2 == 0){
                ans += odd;
                even ++;
            }else{
                ans += even;
                odd ++;
            }
            ans = ans%mod;
        }
        return ans;
    }
};