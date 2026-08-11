class Solution {
public:
    int missingInteger(vector<int>& nums) {
        vector<bool> v(52, false);
        for (int i = 0; i < nums.size(); i++) {
            v[nums[i]] = true;
        }
        int sum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1) {
                sum += nums[i];
            } else {
                break;
            }
        }
        if (sum > 50)
            return sum;

        for (int i = sum; i < 52; i++) {
            if (!v[i]) {
                return i;
            }
        }

        return 0;
    }
};