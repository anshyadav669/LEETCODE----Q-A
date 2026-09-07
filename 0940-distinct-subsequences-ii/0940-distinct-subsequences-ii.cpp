class Solution {
public:
    int distinctSubseqII(string s) {
        const long long MOD = 1e9 + 7;

        vector<long long> end(26, 0);
        long long total = 0;

        for (char ch : s) {
            int i = ch - 'a';

            // New subsequences ending with ch
            long long newEnding = (total + 1) % MOD;

            // Remove old subsequences ending with ch
            total = (total - end[i] + newEnding + MOD) % MOD;

            // Update count for this character
            end[i] = newEnding;
        }

        return total;
    }
};