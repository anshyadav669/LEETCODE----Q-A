class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int Tsum = accumulate(nums.begin(), nums.end(), 0);

        if (Tsum % 2 != 0)
            return false;
        int sum = Tsum / 2;
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
        for(int i=0;i<n+1;i++){
            dp[i][0]=true;
        }

        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < sum + 1; j++) {
                bool take = false;
                if (nums[i - 1] <= j) {
                    take = dp[i - 1][j - nums[i - 1]];
                }
                bool skip = dp[i - 1][j];

                dp[i][j] = take || skip;
            }
        }

        return dp[n][sum];
    }
};
