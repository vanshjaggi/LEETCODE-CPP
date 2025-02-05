//BRUTE FORCE
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        while(n%2 == 0){
            n=n/2;
        }
        return (n==1);
    }
};

//using floor and ceil
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0) return false;
        return (ceil(log2(n)) == floor(log2(n)));
    }
};

//And operation between multiple of 2 and next lower number will always give 0
//1000 & 0111 = 0

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n>0 && ((n & (n-1))==0));
    }
};