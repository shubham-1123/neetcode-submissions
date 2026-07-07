class Solution {
public:
    int findSetBits(int n){
        int count = 0;
        while(n){
            if(n&1){
                count ++;
            }
            n >>=1;
        }
        return count;
    }
    vector<int> countBits(int n) {
        if(n == 0) return {0};
        vector<int> arr(n+1, 0);
        arr[1] = 1;
    
        for(int i=2;i<=n;i++){
            if((i&(i-1)) == 0) //power of two
                arr[i] = 1;
            else 
                arr[i] = findSetBits(i);
        }
        return arr;
    }
};
