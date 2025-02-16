//BRUTE FORCE
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<>> pq(nums.begin(), nums.end());
        int cnt = 0;
        while(pq.top()<k){
            long long x = pq.top();
            pq.pop();
            long long y = pq.top();
            pq.pop();
            pq.push(2*x+y);
            cnt++;
        }
        return cnt;
    }
};


//Using Minimum heap 
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<>> pq(nums.begin(), nums.end());
        int cnt = 0;
        while(pq.top()<k){
            long long x = pq.top();
            pq.pop();
            long long y = pq.top();
            pq.pop();
            pq.push(2*x+y);
            cnt++;
        }
        return cnt;
    }
};