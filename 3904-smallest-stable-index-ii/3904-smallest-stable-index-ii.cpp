class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> suffmin(n);
        suffmin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffmin[i] = min(suffmin[i + 1], nums[i]);
        }

        int premax = 0;
        for (int i = 0; i < n; i++) {
            premax = max(premax, nums[i]);
            if (premax - suffmin[i] <= k) {
                return i;
            }
        }
        return -1;
    }
};