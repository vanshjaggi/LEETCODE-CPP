// thought of a brute force method and it worked. 

class Solution {
public:
    int romanToInt(string s) {
        int num = 0;
        const vector<pair<int,string>> values = {{1000,"M"},{900,"CM"},{500,"D"},{400,"CD"},{100,"C"},{90,"XC"},{50,"L"},{40,"XL"},{10,"X"},{9,"IX"},{5,"V"},{4,"IV"},{1,"I"}};
        for(int i = 0;i<s.length();){
            for(int j = 0;j<values.size();j++){
                if(s.substr(i,values[j].second.size()) == values[j].second){
                    num += values[j].first;
                    i += values[j].second.size();
                    break;
                }
            }
        }
        return num;
    }
};


//can be in O(n) also by using unordered_map and a single loop

class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        unordered_map<char, int> roman = {
            {'I', 1},
            {'V', 5},
            {'X', 10}, 
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        for (int i = 0; i < s.size() - 1; i++) {
            if (roman[s[i]] < roman[s[i + 1]]) {
                res -= roman[s[i]];
            } else {
                res += roman[s[i]];
            }
        }

        return res + roman[s[s.size() - 1]];        
    }
};