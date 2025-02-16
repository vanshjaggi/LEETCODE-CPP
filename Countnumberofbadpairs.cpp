//Brute Force 

class Solution {
    public:
        long long countBadPairs(vector<int>& nums) {
            int n = nums.size();
            long long cnt = 0;
            for(int i = 0; i< n; i++){
                for(int j = i; j<n; j++){
                    if(j-i != nums[j] - nums[i]){
                        cnt++;
                    }
                }
            }
            return cnt;
        }
    };


//OPTIMAL using maths 
class Solution {
    public:
        long long countBadPairs(vector<int>& nums) {
            unordered_map<int,int> freq;
            long good = 0;
            for(int i = 0;i<nums.size();i++){
                int key = nums[i] - i;
                good += freq[key];
                freq[key]++;
            }
            long totalpairs = static_cast<long>((nums.size()) * (nums.size() - 1)) / 2;
            return totalpairs-good;
        }
    };
    
    