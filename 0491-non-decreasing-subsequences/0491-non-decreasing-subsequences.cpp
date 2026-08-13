class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& nums, int start, vector<int>& curr) {
        if (curr.size() >= 2) {
            ans.push_back(curr);
        }

        unordered_set<int> used;

        for (int i = start; i < nums.size(); i++) {

            // Avoid duplicates at the same level
            if (used.count(nums[i])) {
                continue;
            }

            used.insert(nums[i]);

            // Maintain non-decreasing order
            if (!curr.empty() && nums[i] < curr.back()) {
                continue;
            }

            curr.push_back(nums[i]);

            solve(nums, i + 1, curr);

            curr.pop_back();
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> curr;       // Create actual vector
        solve(nums, 0, curr);   // Pass it by reference
        return ans;
    }
};