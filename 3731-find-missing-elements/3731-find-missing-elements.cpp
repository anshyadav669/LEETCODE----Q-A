class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());

        vector<int> ans;
        int j = 0;

        for (int i = mn; i <= mx; i++) {
            if (j < nums.size() && nums[j] == i) {
                while (j < nums.size() && nums[j] == i) {
                    j++;  // skip duplicates
                }
            } else {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
