class Solution {
public:
    bool isPossible(vector<int>& ranks, long long mid, int cars) {
        int n = ranks.size();
        long long countOfCars = 0;
        for (int i = 0; i < n; i++) {
            countOfCars += (long long)(sqrt((double)mid / ranks[i]));
        }
        if (countOfCars >= cars)
            return true;

        return false;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        int n = ranks.size();
        long long low = 1;
        long long maxi = *max_element(ranks.begin(), ranks.end());
        long long high = maxi * cars * cars;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            bool isValid = isPossible(ranks, mid, cars);
            if (isValid) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};