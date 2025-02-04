class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int cur_sum = nums[0];
        int max_sum = 0;
        for(int i = 1; i<nums.size(); i++){
            if(nums[i]>nums[i-1]){
                cur_sum += nums[i];
            }else{
                max_sum = max(max_sum, cur_sum);
                cur_sum = nums[i];
            }
        }
        return max(max_sum, cur_sum);
    }
};