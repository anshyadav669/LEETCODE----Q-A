class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1;
        int n = nums.size();
        arr1.push_back(nums[0]);
        vector<int> arr2;
        arr2.push_back(nums[1]);
        for (int i = 3; i <= n; i++) {
            if (arr1[arr1.size() - 1] > arr2[arr2.size() - 1]) {
                arr1.push_back(nums[i - 1]);
            } else {
                arr2.push_back(nums[i - 1]);
            }
        }
        arr1.insert(arr1.end(), arr2.begin(), arr2.end());

        return arr1;
    }
};