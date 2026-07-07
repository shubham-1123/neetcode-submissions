class Solution {
public:
    void sortColors(vector<int>& arr) {
        int mid = 0, left = 0, right = arr.size()-1;

        while(mid <= right){
            if(arr[mid] == 0){
                swap(arr[left], arr[mid]);
                left ++;
                mid ++;
                continue;
            }
            if(arr[mid] == 1){
                mid ++ ;
                continue;
            }
            if(arr[mid] == 2){
                swap(arr[right--], arr[mid]);
                continue;
            }
        }
    }
};