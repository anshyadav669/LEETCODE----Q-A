class Solution {
public:
    int smallestNumber(int n, int t) {
        while (true) {
            long long prod = 1;
            int x = n;

            if (x == 0)
                prod = 0;
            else {
                while (x > 0) {
                    prod *= (x % 10);
                    x /= 10;
                }
            }

            if (prod % t == 0)
                return n;

            n++;
        }
    }
};