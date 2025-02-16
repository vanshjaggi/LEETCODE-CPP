//Loops 

class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.length()>0 && s.length()>s.find(part)){
           s.erase(s.find(part),part.length());
        }
        return s;
    }
};

//Recursion
class Solution {
    public:
        string removeOccurrences(string s, string target) {
            size_t pos = s.find(target);
            if (pos != string::npos) {
                s.erase(pos, target.length());
                return removeOccurrences(s, target);
            }
            return s;
        }
    };