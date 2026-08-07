class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums,
                                       int indexDiff,
                                       int valueDiff) {

        multiset<long long> window;

        for (int i = 0; i < nums.size(); i++) {

            // Remove element that is outside the sliding window
            if (i > indexDiff) {
                window.erase(window.find(nums[i - indexDiff - 1]));
            }

            // Find the first element >= nums[i] - valueDiff
            auto it = window.lower_bound((long long)nums[i] - valueDiff);

            // Check if it lies within nums[i] + valueDiff
            if (it != window.end() &&
                *it <= (long long)nums[i] + valueDiff) {
                return true;
            }

            window.insert(nums[i]);
        }

        return false;
    }
};