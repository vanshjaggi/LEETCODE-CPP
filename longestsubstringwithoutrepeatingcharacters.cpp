class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int maxlength = 0;
        unordered_set<char> charset;

        for (int right = 0; right<s.length();right++){
            while(charset.find(s[right]) != charset.end()){
                charset.erase(s[left]);
                left++;
            }

            charset.insert(s[right]);
            maxlength = max(maxlength,right-left+1);
        }
        return maxlength;
    }
};
