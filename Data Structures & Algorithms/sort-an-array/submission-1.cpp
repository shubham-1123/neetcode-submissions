class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        if(nums.size() == 1)return nums;
        mergesort(nums, 0, nums.size()-1);
        return nums;
    }
    void mergesort(vector<int>& arr, int left, int right){
        if(left < right){
            int mid = (left+right)/2;
            mergesort(arr, left, mid);
            mergesort(arr, mid+1, right);
            merge(arr, left, mid, right);
        }
    }
    void merge(vector<int>& arr, int left, int mid , int right){
        int i = left, j = mid+1;
        vector<int> aux(right-left+1);
        int k = 0;
        while(i <= mid && j<= right){
            if(arr[i] <= arr[j]){
                aux[k++] = arr[i++];
            }else{
                aux[k++] = arr[j++];
            }
        }
        while(i <= mid){
            aux[k++] = arr[i++];
        }
        while(j<=right){
            aux[k++] = arr[j++];
        }
        k =0 ;
        for(i = left;i<=right;i++){
            arr[i] = aux[k++];
        }
        return;
    }
};