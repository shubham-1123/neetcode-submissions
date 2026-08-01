class Solution {
public:
    void merge(vector<int>& nums, int left, int mid, int right){
        int n1 = mid-left+1;
        int n2 = right-mid;

        vector<int> left_arr(n1), right_arr(n2);
        for(int i=0;i<n1;i++){
            left_arr[i] = nums[left+i];
        }
        for(int i=0;i<n2;i++){
            right_arr[i] = nums[mid+1+i];
        }

        int i=0, j=0, k = left;

        while(i < n1 && j < n2){
            if(left_arr[i] <= right_arr[j]){
                nums[k] = left_arr[i++];
            }else{
                nums[k] = right_arr[j++];
            }
            k ++;
        }

        while(i < n1){
            nums[k++] = left_arr[i++];
        }
        while(j < n2){
            nums[k++] = right_arr[j++];
        }
    }
    void mergeSort(vector<int>& nums, int left, int right){
        if(left < right){
            int mid = left + (right-left)/2;
            mergeSort(nums, left, mid);
            mergeSort(nums, mid+1, right);

            merge(nums, left, mid, right);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        if(nums.size() == 1)return nums;
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};