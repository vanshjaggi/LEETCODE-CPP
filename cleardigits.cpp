class Solution {
    public:
        string clearDigits(string s) {
            for(int i = 1; i<s.length() ; i++){
                if(isdigit(s[i])){
                    s.erase(i-1, 2);
                    i=0;
                }
            }
            return s;
        }
    };