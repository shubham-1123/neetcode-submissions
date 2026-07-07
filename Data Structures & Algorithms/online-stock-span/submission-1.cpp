class StockSpanner {
public:
    stack<pair<int,int>> st;
    int index;
    StockSpanner() {
        index = 0;
    }
    
    int next(int price) {
        int ans = 1;
        while(!st.empty()){
            if(st.top().first <= price){
                ans = index+1 ;
                st.pop();
            }else{
                ans = index  - st.top().second;
                break;
            }
        }
        st.push({price,index});
        index ++;
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */