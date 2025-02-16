//O(NlogN)
class Solution {
    public:
        int digitSum(int n) {
            int sum = 0;
            while (n != 0) {
                int last = n % 10;
                sum += last;
                n /= 10;
            }
            return sum;
        }
        int maximumSum(vector<int>& nums) {
            unordered_map<int,priority_queue<int>> m;
            int n = nums.size();
            for(int i = 0; i<n; i++){
                int dsum = digitSum(nums[i]);
                m[dsum].push(nums[i]);
            }
            int maxr = -1;
            for(auto& pair : m){
                int key = pair.first;
                priority_queue<int>& pq = pair.second;
                int sum = 0;
                if(pair.second.size() > 1){
                    sum+=pq.top();
                    pq.pop();
                    sum+=pq.top();
                    maxr = max(sum,maxr);
                }
            }
            return maxr;
        }
    };

//O(N)
    class Solution {                                                      
        public:                                                               
            int maximumSum(vector<int>& nums) {                               
                int mp[82];                                                   
                memset(mp,-1,sizeof(mp));                                     
                int ans = -1;                                                 
                                                                              
                for(int num:nums){                                            
                    int sumDigits =0, temp = num;                             
                    while(temp) sumDigits+=temp%10,temp/=10;                  
                    if(mp[sumDigits] != -1) ans = max(ans, num+mp[sumDigits]);
                    mp[sumDigits] = max(mp[sumDigits], num);                  
                }                                                             
                return ans;                                                   
            }                                                                 
        };                                                                     