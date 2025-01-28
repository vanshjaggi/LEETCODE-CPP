class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string st="";
        sort(strs.begin(),strs.end());
        int n = strs.size();
        for(int i = 0;i<min(strs[0].size(),strs[n-1].size());i++){
            if(strs[0][i] != strs[n-1][i]){
                return st;
            }
            st+=strs[0][i];
        }
        return st;

    }
};