//Brute Force

class Solution {
public:
    bool canPartition(string numStr, int target, int start = 0, int currSum = 0) {
        if (start == numStr.size()) {
            return currSum == target;
        }
        
        int sum = 0;
        for (int j = start; j < numStr.size(); ++j) {
            sum = sum * 10 + (numStr[j] - '0');
            if (canPartition(numStr, target, j + 1, currSum + sum)) {
                return true;
            }
        }
        return false;
    }
    int punishmentNumber(int n) {
        int totalSum = 0;
        for (int i = 1; i <= n; ++i) {
            int square = i * i;
            if (canPartition(to_string(square), i)) {
                totalSum += square;
            }
        }
        return totalSum;
    }
};

//Backtracking

class Solution {
public:
    static inline bool partition(int x, int target) {
        if (x==target) return 1;
        if (x==0) return target==0; 
        const int m0=min(x, 1000); 
        [[unroll]] 
        for (int m=10; m<=m0; m*=10) {
            if (partition(x/m, target-x%m)) return 1;
        }
        return 0;
    }

    static int punishmentNumber(int n) {
        int sum=0;
        for (int i=1; i<=n; i++) {
            if (i%9!=0 && i%9!=1) 
                continue;// Consider only (i%9)**2==i%9
            const int x=i*i;
            sum+=(partition(x, i))?x:0;
        }
        return sum;
    }
};