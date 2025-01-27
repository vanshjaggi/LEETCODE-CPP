//FIRST ATTEMPT - BRUTE FORCE METHOD (TIME LIMIT EXCEEDS)

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int max_area = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                // Calculate the area
                int area = (j - i) * min(height[i], height[j]);
                // Update the maximum area
                max_area = max(max_area, area);
            }
        }
        
        return max_area;
    }
};


//ANOTHER METHOD CAN BE USING TWO POINTER

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0,right = (height.size())-1;
        int area = 0,max_area=0;
        
        while(left<right){
            area = (right-left)*min(height[left],height[right]);
            max_area = max(max_area,area);
            if(height[right]>height[left]){
                left++;
            }else{
                right--;
            }
        }
        return max_area;
    }
};