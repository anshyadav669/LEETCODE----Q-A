class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);

        // Count frequencies
        for (char c : s)
            freq[c - 'a']++;

        string left = "";
        char mid = '\0';

        // Build left half in lexicographical order
        for (int i = 0; i < 26; i++) {
            left += string(freq[i] / 2, 'a' + i);

            if (freq[i] % 2)
                mid = 'a' + i;
        }

        string right = left;
        reverse(right.begin(), right.end());

        if (mid != '\0')
            return left + mid + right;

        return left + right;
    }
};