class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> need(26, 0);

        for (char c : licensePlate) {
            if (isalpha(c)) {
                need[tolower(c) - 'a']++;
            }
        }

        string ans;

        for (string &word : words) {
            vector<int> cnt(26, 0);

            for (char c : word) {
                cnt[tolower(c) - 'a']++;
            }

            bool ok = true;
            for (int i = 0; i < 26; i++) {
                if (cnt[i] < need[i]) {
                    ok = false;
                    break;
                }
            }

            if (ok && (ans.empty() || word.size() < ans.size())) {
                ans = word;
            }
        }

        return ans;
    }
};