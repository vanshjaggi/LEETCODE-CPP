// Brute Force Method

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        vector<int> merged;
        for(int i = 0;i<n;i++){
            merged.push_back(nums1[i]);
        }
        for(int i = 0; i<m;++){
            merged.push_back(nums2[i]);
        }
        sort(merged.begin(), merged.end());

        int total = merged.size();

        if(total%2==1){
            return static_cast<double>(merged[total/2]);
        }
        else{
            return static_cast<double>((merged[total/2] + merged[total / 2 - 1]))/2.0;
        }
    }
};

//Two Pointer Method

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Get the sizes of both input arrays.
        int n = nums1.size();
        int m = nums2.size();

        // Merge the arrays into a single sorted array.
        vector<int> merged;
        for (int i = 0; i < n; i++) {
            merged.push_back(nums1[i]);
        }
        for (int i = 0; i < m; i++) {
            merged.push_back(nums2[i]);
        }

        // Sort the merged array.
        sort(merged.begin(), merged.end());

        // Calculate the total number of elements in the merged array.
        int total = merged.size();

        if (total % 2 == 1) {
            // If the total number of elements is odd, return the middle element as the median.
            return static_cast<double>(merged[total / 2]);
        } else {
            // If the total number of elements is even, calculate the average of the two middle elements as the median.
            int middle1 = merged[total / 2 - 1];
            int middle2 = merged[total / 2];
            return (static_cast<double>(middle1) + static_cast<double>(middle2)) / 2.0;
        }
    }
};

//BINARY SEARCH METHOD

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() < nums2.size()) return findMedianSortedArrays(nums2, nums1);
        int n = nums1.size(), m = nums2.size(), tot = n + m, half = tot / 2, l = 0, r = m;
        while(l <= r) {
            int i = (r + l) / 2, j = half - i;
            int rightB = i == m ? INT_MAX : nums2[i], leftB = i == 0 ? INT_MIN : nums2[i - 1];
            int rightA = j == n ? INT_MAX : nums1[j], leftA = j == 0 ? INT_MIN : nums1[j - 1];
            if(leftB <= rightA && leftA <= rightB) 
                return tot % 2 == 0 ? (double)(min(rightA, rightB) + max(leftA, leftB)) / 2.0 : (double)min(rightA, rightB);
            if(leftA > rightB) l = i + 1; else r = i - 1;
        }
        return -1;
    }
};