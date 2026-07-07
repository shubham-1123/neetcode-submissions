/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findPivot(MountainArray &mountainArr){
        int left = 0, right = mountainArr.length()-1;
        while(left < right){
            int mid = (left + right)/2;
            if(mountainArr.get(mid) < mountainArr.get(mid+1))
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
    int findValueLeft(int target, int left, int right, MountainArray &mountainArr){
        while(left <= right){
            int mid = (left + right)/2;
            if(mountainArr.get(mid) == target)
                return mid;
            if(mountainArr.get(mid) >  target){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return -1;
    }
    int findValueRight(int target, int left, int right, MountainArray &mountainArr){
        while(left <= right){
            int mid = (left + right)/2;
            if(mountainArr.get(mid) == target)
                return mid;
            if(mountainArr.get(mid) >  target){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return -1;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int mid = findPivot(mountainArr);
        // cout << mid << endl;
        int index = findValueLeft(target, 0, mid, mountainArr);
        // cout << index << endl;
        if(index != -1)
            return index;
        int right = mountainArr.length()-1;
        index = findValueRight(target, mid+1, right, mountainArr);
        // cout << index << endl;
        if(index != -1)
            return index;
        return -1;
    }
};