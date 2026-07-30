class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int count = 1;
            for (int j = i + 1; j < n; j++) {
                if (nums[i] == nums[j]) {
                    count++;
                }
                 else
                    break;
            }
            if (count < 3) {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};