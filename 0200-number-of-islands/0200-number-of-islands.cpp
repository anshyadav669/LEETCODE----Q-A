class Solution {
public:
    void bfs(int i, int j, vector<vector<int>>& vis,
             vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        q.push({i, j});
        vis[i][j] = 1;

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        while (!q.empty()) {

            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            // Check 4 directions
            for (int k = 0; k < 4; k++) {

                int newr = row + delrow[k];
                int newc = col + delcol[k];

                if (newr >= 0 && newr < n &&
                    newc >= 0 && newc < m &&
                    !vis[newr][newc] &&
                    grid[newr][newc] == '1') {

                    vis[newr][newc] = 1;
                    q.push({newr, newc});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == '1' && !vis[i][j]) {

                    cnt++;

                    bfs(i, j, vis, grid);
                }
            }
        }

        return cnt;
    }
};