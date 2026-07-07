class MinStack {
public:
    stack<int> st1;
    stack<int> st2;
    MinStack() {
        
    }
    
    void push(int val) {

        if(st1.empty()){
            st1.push(val);
            st2.push(val);
        }else{
            int minVal = st2.top();
            if(val < minVal){
                st2.push(val);
            }else{
                st2.push(minVal);
            }
            st1.push(val);
        }
        
    }
    
    void pop() {
        if(!st1.empty() && !st2.empty()){
            st1.pop();
            st2.pop();
        }
    }
    
    int top() {
        if(!st1.empty())
            return st1.top();
    }
    
    int getMin() {
        if(!st2.empty())
            return st2.top();
    }
};
