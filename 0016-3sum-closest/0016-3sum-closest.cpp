class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int dif = INT_MAX, ans = 0,n = nums.size();
        for (int i = 0; i < n; i++) {
            int j = i + 1, k = n - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target) {
                    return sum;
                } else if (abs(sum - target) < dif) {
                    dif = abs(sum - target);
                    ans = sum;
                }
                if (sum > target) {
                    k--;
                } else {
                    j++;
                }
            }
        }
        return ans;
    }
};
