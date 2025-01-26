// BRUTE FORCE METHOD

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length()<=1){
            return s;
        }
        int max_len=1;
        string max_str=s.substr(0,1);

        for(int i = 0; i<s.length();++i){
            for(int j = i + max_len; j <= s.length() ; ++j ) {
                if( j - 1 > max_len && isPalindrome( s.substr( i , j - i ) ) ) {
                    max_len = j-1;
                    max_str=s.substr(i , j-1);
                }
            }
        }
        return max_str;
    }
    private:
    bool isPalindrome(const string& str){
        int left=0;
        int right = str.length() - 1;
        while(left<right){
            if(str[left] != str[right]){
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }

};


// EXPANDING FROM THE MIDDLE

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length()<=1){
            return s;
        }
        auto expandfromcenter = [&](int left, int right){
            while(left >= 0 && right<s.length() && s[left] == s[right]){
                left--;
                right++;
            }
            return s.substr(left+1,right-left-1);
        };
        
        string max_str = s.substr(0,1);
        for(int i = 0;i<s.length() -1; i++){
            string odd = expandfromcenter(i,i);
            string even = expandfromcenter(i,i+1);

            if(odd.length() > max_str.length()){
                max_str = odd;
            }
            if(even.length()>max_str.length()){
                max_str = even;
            }
        }
        return max_str;
    }
};


// DYNAMIC PROGRAMMING

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length()<=1){
            return s;
        }
        int max_len = 1;
        int start = 0;
        int end = 0;

        vector<vector<bool>> dp(s.length(),vector<bool>(s.length(),false));
        for(int i = 0;i<s.length();++i){
            dp[i][i] = true;
            for(int j = 0; j<i;++j){
                if(s[j]==s[i] &&(i-j<=2 || dp[j+1][i-1])){
                    dp[j][i] = true;
                    if(i-j+1>max_len){
                        max_len = i-j+1;
                        start = j;
                        end = i;
                    }
                }
            }
        }
        return s.substr(start,end-start+1);
    }
};