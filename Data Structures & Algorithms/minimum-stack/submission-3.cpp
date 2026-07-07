class MinStack {
public:
    stack<pair<int,int>> st;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push({val, val});
        }else{
            int minVal = st.top().second;
            if(val < minVal){
                st.push({val, val});
            }else{
                st.push({val, minVal});
            }
        }
    }
    
    void pop() {
        if(!st.empty())
            st.pop();
    }
    
    int top() {
        if(!st.empty())
            return st.top().first;
    }
    
    int getMin() {
        if(!st.empty()){
            return st.top().second;
        }
    }
};
