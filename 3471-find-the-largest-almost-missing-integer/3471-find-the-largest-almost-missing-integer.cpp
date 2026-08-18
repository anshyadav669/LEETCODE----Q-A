class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> freq;
        int ans = -1;
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }

        if (k == 1) {
            int x = -1;
            for (int i = 0; i < n; i++) {
                if (freq[nums[i]] == 1) {
                    x = max(x, nums[i]);
                }
            }
            return x;
        } else if (k == n) {
            return *max_element(nums.begin(), nums.end());
        }

        else {
            if (freq[nums[0]] == 1) {
                ans = nums[0];
            }
            if (freq[nums[n - 1]] == 1) {
                ans = max(ans, nums[n-1]);
            }

            return ans;
        }
    }
};