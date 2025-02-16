//BRUTE FORCE

class ProductOfNumbers {
    public:
        vector<int> stream;
        ProductOfNumbers() {
    
        }
        
        void add(int num) {
            stream.push_back(num);
        }
        
        int getProduct(int k) {
            int product = 1;
            int n = stream.size();
            for (int i = n - k; i < n; ++i) product *= stream[i];
            return product;
        }
    };




//OPTIMIZED TO O(1)

class ProductOfNumbers {
    public:
        vector<int> p{1};
        ProductOfNumbers() {}
    
        void add(int num) {
            if (num != 0) {
                p.push_back(num * p.back());
            } else {
                p.clear();
                p.push_back(1);
            }
        }
    
        int getProduct(int k) {
            return k < p.size() ? p.back() / p[p.size() - k - 1] : 0;
        }
    };