class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        vector<long long> prefix(n + 1, 0);

        // Prefix sums
        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + stones[i - 1];
        }

        // dp[i] = maximum score difference
        // when the current combined prefix ends at i
        vector<long long> dp(n + 1, 0);

        long long best = LLONG_MIN;

        for (int i = n - 1; i >= 1; i--) {
            best = max(best, prefix[i + 1] - dp[i + 1]);
            dp[i] = best;
        }

        return dp[1];
    }
};