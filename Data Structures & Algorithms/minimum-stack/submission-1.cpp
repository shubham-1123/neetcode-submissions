// class MinStack {
// public:
//     MinStack() {
        
//     }
    
//     void push(int val) {
        
//     }
    
//     void pop() {
        
//     }
    
//     int top() {
        
//     }
    
//     int getMin() {
        
//     }
// };



typedef long long ll;
class MinStack {
public:
    stack<ll> st;
    ll minVal ;
    MinStack() {
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val) ;
            minVal = val ;
        }
        else if(val >= minVal){
            st.push(val);
        }
        else{
            st.push(2LL*val-minVal) ;
            minVal = val ;
        }
    }
    
    void pop() {
        if(st.empty())return;
        ll topVal = st.top() ;
        st.pop();
        if(topVal < minVal){
            minVal = 2LL*minVal - topVal;
        }
    }
    
    int top() {
        if(st.empty())return -1;
        ll topVal = st.top();

        if(topVal >= minVal)
            return topVal;
        else
            return (int)minVal;
    }
    
    int getMin() {
        if(st.empty())return -1;
        return (int)minVal;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */




// typedef long long ll ;
// class MinStack {
// public:
//     stack<ll> st;
//     ll minVal ;
//     MinStack() {
        
//     }
    
//     void push(int val) {
//         if(st.empty()){
//             st.push(val);
//             minVal= val;
//         }else if(val >= st.top()){
//             st.push(val);
//         }else{
//             st.push(2LL*val-minVal);
//             minVal = val;
//         }
//     }
    
//     void pop() {
//         if(st.empty())return ;
//         ll topVal = st.top() ;
//         st.pop() ;
//         if(topVal < minVal){
//             minVal = 2LL*minVal-topVal;
//         }
//     }
    
//     int top() {
//         if(st.empty())return -1;
//         ll topVal = st.top() ;
//         if(topVal >= minVal)
//             return (int)topVal;
//         else 
//             return (int)minVal;
//     }
    
//     int getMin() {
//         if(st.empty())return -1;
//         return (int)minVal;
//     }
// };
