class Solution {
public:
    long long minimumSteps(string s) {
        long long ans = 0;
        long long black = 0;

        for (char ch : s) {
            if (ch == '1') {
                black++;
            } else {
                ans += black;
            }
        }

        return ans;
    }
};