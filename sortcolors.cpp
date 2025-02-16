//pointer and hash (O(n))
class Solution {
    public:
        void sortColors(vector<int>& nums) {
            unordered_map<int,int> data = {{0,0},{1,0},{2,0}};
    
            for(int num : nums){
                data[num]++;
            }
            int idx = 0;
            for(int i = 0; i<3; i++){
                int freq = data[i];
                for(int j = 0;j<freq;j++){
                    nums[idx] = i;
                    idx++;
                }
            }
        }
    };

//sorting method(O(nlogn))

class Solution {
    public:
        void merge(vector<int>& arr, int left, int mid, int right) {
            int n1 = mid - left + 1, n2 = right - mid;
            vector<int> leftArr(arr.begin() + left, arr.begin() + mid + 1);
            vector<int> rightArr(arr.begin() + mid + 1, arr.begin() + right + 1);
    
            int i = 0, j = 0, k = left;
            while (i < n1 && j < n2) {
                if (leftArr[i] <= rightArr[j]) arr[k++] = leftArr[i++];
                else arr[k++] = rightArr[j++];
            }
            while (i < n1) arr[k++] = leftArr[i++];
            while (j < n2) arr[k++] = rightArr[j++];
        }
    
        void mergeSort(vector<int>& arr, int left, int right) {
            if (left < right) {
                int mid = left + (right - left) / 2;
                mergeSort(arr, left, mid);
                mergeSort(arr, mid + 1, right);
                merge(arr, left, mid, right);
            }
        }
    
        void sortColors(vector<int>& arr) {
            mergeSort(arr, 0, arr.size() - 1);
        }
    };
    