class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        int minPrice = prices[0];
        for(int i=1;i<prices.size();i++){
            if(prices[i] < minPrice){
                minPrice = prices[i];
            }else{
                maxprofit = max(maxprofit, prices[i]-minPrice);
            }
        }
        return maxprofit;
    }
};
