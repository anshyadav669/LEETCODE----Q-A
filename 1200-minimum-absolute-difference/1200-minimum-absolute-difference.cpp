class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int small = arr[1] - arr[0];
        for (int i = 1; i < arr.size(); ++i) {
            small = min(small, arr[i] - arr[i - 1]);
        }
        vector<vector<int>> ans;
        for (int i = 1; i < arr.size(); ++i) {
            if (arr[i] - arr[i - 1] == small) {
                ans.emplace_back(vector<int>({arr[i - 1], arr[i]}));
            }
        }
        return ans;
    }
};