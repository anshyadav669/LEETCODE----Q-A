class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> mp;

        for (auto &v : reservedSeats) {
            mp[v[0]] |= (1 << (v[1] - 1));
        }

        long long ans = 2LL * n;

        // 0111100000 -> seats 2-5
        int left = (1 << 1) | (1 << 2) | (1 << 3) | (1 << 4);

        // 0000111100 -> seats 4-7
        int middle = (1 << 3) | (1 << 4) | (1 << 5) | (1 << 6);

        // 0000011110 -> seats 6-9
        int right = (1 << 5) | (1 << 6) | (1 << 7) | (1 << 8);

        for (auto &[row, mask] : mp) {
            bool canLeft = (mask & left) == 0;
            bool canMiddle = (mask & middle) == 0;
            bool canRight = (mask & right) == 0;

            if (canLeft && canRight) {
                // 2 groups
            }
            else if (canLeft || canMiddle || canRight) {
                ans--;  // this row gets only 1 group
            }
            else {
                ans -= 2; // this row gets 0 groups
            }
        }

        return ans;
    }
};