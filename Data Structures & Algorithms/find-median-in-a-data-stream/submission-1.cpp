class MedianFinder {
public:
    priority_queue<int> leftHalf;
    priority_queue<int, vector<int>, greater<int>> rightHalf;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(leftHalf.empty() or num <= leftHalf.top()){
            leftHalf.push(num);
        }
        else {
            rightHalf.push(num);
        }

        if(leftHalf.size() > rightHalf.size()+1){
            rightHalf.push(leftHalf.top());
            leftHalf.pop();
        }
        else if(leftHalf.size() < rightHalf.size()){
            leftHalf.push(rightHalf.top());
            rightHalf.pop();
        }
    }
    
    double findMedian() {
        if(leftHalf.size() > rightHalf.size()){
            return leftHalf.top();
        }

        return  (leftHalf.top() + rightHalf.top())/2.0;
    }
};
