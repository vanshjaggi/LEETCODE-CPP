//dividing two integers without using multiplication and division operators. Basically using Bit Manipulation to gain good time complexity.

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == divisor) {
            return 1;
        }
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX; // Handling overflow case
        }
        long long n = abs((long long) dividend);
        long long d = abs((long long) divisor);
        long long ans = 0;
        int sign = 1;
        if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
            sign = -1;
        
        while(n>=d){
            long long temp = d, multiple = 1;
            while(n>=(temp<<1) && (temp<<1) > 0){
                temp<<=1;
                multiple<<=1;
            }
            ans += multiple;
            n -= temp;
        }
        return sign * ans;
    }
};
