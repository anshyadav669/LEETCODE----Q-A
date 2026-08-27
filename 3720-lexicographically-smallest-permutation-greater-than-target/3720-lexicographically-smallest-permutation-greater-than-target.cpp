class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        // Frequency of characters in s
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        // Try to make the answer greater at position i.
        // We start from the right because we want the earliest
        // possible prefix to remain equal to target.
        for (int i = n - 1; i >= 0; i--) {

            // Restore frequency for the suffix after position i.
            vector<int> cnt = freq;

            // Match target[0 ... i-1]
            bool possible = true;

            for (int j = 0; j < i; j++) {
                int x = target[j] - 'a';

                if (cnt[x] == 0) {
                    possible = false;
                    break;
                }

                cnt[x]--;
            }

            if (!possible)
                continue;

            // At position i, choose the smallest character
            // strictly greater than target[i].
            int x = target[i] - 'a';

            for (int c = x + 1; c < 26; c++) {

                if (cnt[c] == 0)
                    continue;

                string ans = target.substr(0, i);

                // Make the first greater choice
                ans += char('a' + c);
                cnt[c]--;

                // Put all remaining characters in sorted order
                for (int k = 0; k < 26; k++) {
                    ans += string(cnt[k], char('a' + k));
                }

                return ans;
            }
        }

        return "";
    }
};