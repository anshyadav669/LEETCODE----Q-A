class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int maxl = 0;
        unordered_map<int, int> freq;
        int left = 0;
        for (int i = 0; i < nums.size(); i++) {
            ++freq[nums[i]];
            while (freq[nums[i]] > k) {
                --freq[nums[left]];
                left++;
            }

            maxl = max(maxl, i - left + 1);
        }

        return maxl;
    }
};