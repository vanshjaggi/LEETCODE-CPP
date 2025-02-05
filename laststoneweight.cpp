class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while(stones.size() > 1){
            sort(stones.begin(),stones.end());
            int diff = stones[stones.size()-1] - stones[stones.size()-2];
            stones.erase(stones.end() - 1);
            stones.erase(stones.end() - 1);
            if(diff!=0) stones.push_back(diff);

        }
        return stones.empty() ? 0 : stones[0];
    }
};