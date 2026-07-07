class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, minStockVal = INT_MAX;
        for(int i=0;i<prices.size();i++){
            if(prices[i] < minStockVal){
                minStockVal = prices[i];
                continue;
            }else{
                profit += (prices[i]-minStockVal);
                minStockVal = prices[i];
            }
        }
        return profit;
    }
};