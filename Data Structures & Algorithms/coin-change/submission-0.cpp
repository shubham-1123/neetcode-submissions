class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int val = solve(coins, amount, 0);
        return (val != INT_MAX)?val:-1;
    }
    int solve(vector<int>& coins, int amount, int i){
        if(amount == 0)return 0;
        if(amount < 0 or i == coins.size()) return INT_MAX;
        
        int take = INT_MAX;

        if(coins[i] > 0){
            take = solve(coins, amount-coins[i], i);
            if(take != INT_MAX) take ++;
        }

        int noTake = solve(coins, amount, i+1);

        return min(take, noTake);
    }
};
