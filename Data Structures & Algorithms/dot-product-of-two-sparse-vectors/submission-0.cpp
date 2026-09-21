class SparseVector {
    vector<int> input;
public:
    
    SparseVector(vector<int> &nums) {
        input = nums;
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int n = input.size();
        int val = 0 ;
        for(int i=0;i<n;i++){
            val += (input[i] * vec.input[i]);
        }
        return val;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
