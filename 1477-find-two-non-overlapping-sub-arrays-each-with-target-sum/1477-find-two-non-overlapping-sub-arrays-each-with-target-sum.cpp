class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        
        const int INF = 1e9;
        
        // best[i] = minimum length of a valid subarray
        // completely inside [0 ... i]
        vector<int> best(n, INF);
        
        unordered_map<int, int> mp;
        mp[0] = -1;
        
        int prefix = 0;
        int ans = INF;
        
        for (int i = 0; i < n; i++) {
            prefix += arr[i];
            
            // Carry forward previous best
            if (i > 0)
                best[i] = best[i - 1];
            
            // Need prefix[j] = prefix - target
            if (mp.count(prefix - target)) {
                int j = mp[prefix - target];
                int len = i - j;
                
                // Previous non-overlapping subarray must end before j
                if (j >= 0 && best[j] != INF) {
                    ans = min(ans, len + best[j]);
                }
                
                // This is the best subarray ending at i
                best[i] = min(best[i], len);
            }
            
            mp[prefix] = i;
        }
        
        return ans == INF ? -1 : ans;
    }
};