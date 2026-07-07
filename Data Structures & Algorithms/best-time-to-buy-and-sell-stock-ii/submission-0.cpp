class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;

        int minPrice = INT_MAX;

        for(int i=0;i<prices.size();i++){
            if(minPrice > prices[i]){
                minPrice = prices[i];
                continue;
            }
            maxProfit += (prices[i]-minPrice); 
            minPrice = prices[i] ;
        }
        return maxProfit;
    }
};