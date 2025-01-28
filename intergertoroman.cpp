//simple solution.  for loop takes the values one by one(larger to smaller) and computes new num and string value at each iteration.

class Solution {
public:
    string intToRoman(int num) {
        string res="";
        const vector<pair<int,string>> values = {{1000,"M"},{900,"CM"},{500,"D"},{400,"CD"},{100,"C"},{90,"XC"},{50,"L"},{40,"XL"},{10,"X"},{9,"IX"},{5,"V"},{4,"IV"},{1,"I"}};
        for(int i = 0;i<values.size();i++){
            while(num>=values[i].first){
                res+=values[i].second;
                num-=values[i].first;
            }
        }
        return res;
    }
};