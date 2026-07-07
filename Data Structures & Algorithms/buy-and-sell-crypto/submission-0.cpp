class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int minVal = prices[0] ;
        for(int i=1;i<prices.size();i++){
            if(prices[i] <= minVal){
                minVal = prices[i];
            }else{
                profit = max(profit, prices[i]-minVal);
            }
        }
        return profit;
    }
};
