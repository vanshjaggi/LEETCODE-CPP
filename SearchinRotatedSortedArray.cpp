class Solution {
private:
    int findPivot(vector<int>& arr){
        int left = 0;
        int right = arr.size() - 1;
        int mid=0;

        while(left<right){
            mid = left + (right -left) / 2;
            if(arr[right]<arr[mid]){
                left = mid+1;
            }else{
                right = mid;
            }
        }
        return left;
    }
    int binarySearch(vector<int>& arr,int left, int right, int k){
        while(left<=right){
            int mid = left + (right - left) /2;
            if(k>arr[mid]){
                left = mid+1;
            }else if(arr[mid] == k){
                return mid;
            }
            else{
                right = mid - 1;
            }
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()){
            return -1;
        }
        int pivot = findPivot(nums);
        if (target >= nums[pivot] && target <= nums.back()) {
            return binarySearch(nums, pivot, nums.size() - 1, target);
        } else {
            return binarySearch(nums, 0, pivot - 1, target);
        }
    }
};