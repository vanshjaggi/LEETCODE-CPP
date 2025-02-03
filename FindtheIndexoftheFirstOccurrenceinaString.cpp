//BRUTE FORCE APPROACH (SLICING APPROACH)

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();

        if (m > n) return -1;

        for (int i = 0; i <= n - m; i++) { 
            if (haystack.substr(i, m) == needle) {
                return i;
            }
        }
        return -1;
    }
};



//2 line code
class Solution {
public:
    int strStr(string haystack, string needle) {
        size_t pos = haystack.find(needle);
        return (pos == string::npos) ? -1 : static_cast<int>(pos);
    }
};
