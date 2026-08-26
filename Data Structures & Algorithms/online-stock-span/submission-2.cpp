class StockSpanner {
public:
    stack<pair<int,int>> st;
    int index;
    StockSpanner() {index =0;}
    
    int next(int price) {
        int stockSpan = 1;
        while(!st.empty()){
            if(st.top().first <= price){
                st.pop();
            }else{
                stockSpan = (index-st.top().second);
                break;
            }
        }

        if(st.empty())
            stockSpan = max(stockSpan, index+1);
        st.push({price, index++});
        return stockSpan;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */