class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        while(left<=right){
            int mid = left+(right-left)/2;
            if((mid == 0 || nums[mid]!= nums[mid-1]) && (mid == right || nums[mid]!= nums[mid+1]))
                return nums[mid];
            if(mid > 0 && nums[mid] == nums[mid-1]){
                if(mid%2 == 0)
                    right = mid-2;
                else 
                    left = mid+1;
            }else{
                if(mid%2)
                    right = mid-1;
                else 
                    left = mid+2;
            }
        }
        return -1; 
    }
};

// class Solution {
// public:
//     int singleNonDuplicate(vector<int>& nums) {
//         int left = 0, right = nums.size() - 1;

//         while (left <= right) {
//             int mid = left + (right - left) / 2;

//             // mid is the single element
//             if ((mid == 0 || nums[mid] != nums[mid - 1]) &&
//                 (mid == right || nums[mid] != nums[mid + 1])) {
//                 return nums[mid];
//             }

//             // Pair is (mid-1, mid)
//             if (mid > 0 && nums[mid] == nums[mid - 1]) {

//                 if (mid % 2 == 0)
//                     right = mid - 2;  // single is left
//                 else
//                     left = mid + 1;   // single is right
//             }

//             // Pair is (mid, mid+1)
//             else {
//                 if (mid % 2 == 1)
//                     right = mid - 1;  // single is left
//                 else
//                     left = mid + 2;   // single is right
//             }
//         }

//         return -1;
//     }
// };

