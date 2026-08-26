class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        vector<int> pos;

        // Store positions of all 1s
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                pos.push_back(i);
            }
        }

        // Not enough 1s
        if (pos.size() < k)
            return "";

        string ans = "";
        int minLen = INT_MAX;

        // Consider every k consecutive 1s
        for (int i = 0; i + k - 1 < pos.size(); i++) {
            int start = pos[i];
            int end = pos[i + k - 1];

            string cur = s.substr(start, end - start + 1);

            if (cur.length() < minLen) {
                minLen = cur.length();
                ans = cur;
            }
            else if (cur.length() == minLen && cur < ans) {
                ans = cur;
            }
        }

        return ans;
    }
};