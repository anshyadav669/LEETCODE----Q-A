class Solution {
public:
    int profit(vector<int>& nums, int i, int n, vector<int>& dp) {
        if (i >= n)
            return 0;
        if (dp[i] != -1)
            return dp[i];

        int steal = nums[i] + profit(nums, i + 2, n,dp);
        int skip = profit(nums, i + 1, n,dp);

        return dp[i] = max(steal, skip);
    }

    int rob(vector<int>& nums) {
        vector<int> dp(101, -1);
        int n = nums.size();
        return profit(nums, 0, n, dp);
    }
};