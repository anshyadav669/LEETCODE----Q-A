class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        long long maxim = LLONG_MIN;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                long long g = gcd(nums[i], nums[j]);
                long long product = 1LL * nums[i] * nums[j];

                maxim = max(maxim, product / (g * g));
            }
        }

        return maxim;
    }
};