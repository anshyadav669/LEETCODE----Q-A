class Solution {
public:

    long long func(int val, vector<int>& piles) {
        long long req = 0;

        for (int i = 0; i < piles.size(); i++) {
            req += piles[i] / val;

            if (piles[i] % val != 0)
                req++;
        }

        return req;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int mx = *max_element(piles.begin(), piles.end());

        int low = 1;
        int high = mx;
        int ans = mx;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            long long ttime = func(mid, piles);

            if (ttime <= h) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};