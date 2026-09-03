class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
         bool hasOdd = false;
        bool hasEven = false;
        int mn = INT_MAX;

        for (int x : nums1) {
            mn = min(mn, x);

            if (x & 1)
                hasOdd = true;
            else
                hasEven = true;
        }

        // Already all have the same parity
        if (!hasOdd || !hasEven)
            return true;

        // Mixed parity:
        // possible only if the minimum element is odd
        return (mn & 1);
    }
};