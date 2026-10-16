class MedianFinder {
    priority_queue<int> left_half; //max heap;
    priority_queue<int, vector<int>, greater<int>> right_half; // min heap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left_half.empty() || num <= left_half.top()){
            left_half.push(num);
        }else{
            right_half.push(num);
        }

        if(left_half.size() > right_half.size()+1){
            right_half.push(left_half.top());
            left_half.pop();
        }
        else if(right_half.size() > left_half.size()){
            left_half.push(right_half.top());
            right_half.pop();
        }
    }

    double findMedian() {
        int l1 = left_half.size();
        int l2 = right_half.size();

        if((l1+l2)%2){
            return (double)left_half.top();
        }
        return (left_half.top() + right_half.top())/2.0;

    }
};
