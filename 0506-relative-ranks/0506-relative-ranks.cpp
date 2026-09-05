class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();

        priority_queue<pair<int, int>> pq;
        vector<string> ans(n);

        for (int i = 0; i < n; i++) {
            pq.push({score[i], i});
        }

        int cnt = 1;

        while (!pq.empty()) {
            int index = pq.top().second;
            pq.pop();

            if (cnt == 1) {
                ans[index] = "Gold Medal";
            }
            else if (cnt == 2) {
                ans[index] = "Silver Medal";
            }
            else if (cnt == 3) {
                ans[index] = "Bronze Medal";
            }
            else {
                ans[index] = to_string(cnt);
            }

            cnt++;
        }

        return ans;
    }
};