class Solution {
public:
    void dfs(int rw, int cl, vector<vector<int>>& grid,
             vector<vector<int>>& vis,
             vector<int>& drow, vector<int>& dcol,
             vector<vector<int>>& ans) {

        int n = grid.size();
        int m = grid[0].size();

        vis[rw][cl] = 1;
        ans[rw][cl] = 2;

        for (int i = 0; i < 4; i++) {
            int nrw = rw + drow[i];
            int ncl = cl + dcol[i];

            if (nrw >= 0 && nrw < n &&
                ncl >= 0 && ncl < m &&
                !vis[nrw][ncl] &&
                grid[nrw][ncl] == 1) {

                dfs(nrw, ncl, grid, vis, drow, dcol, ans);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        // Copy grid
        vector<vector<int>> ans = grid;

        vector<int> drow = {-1, 0, 1, 0};
        vector<int> dcol = {0, 1, 0, -1};

        vector<vector<int>> vis(n, vector<int>(m, 0));

        // First row
        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 1 && !vis[0][j]) {
                dfs(0, j, grid, vis, drow, dcol, ans);
            }
        }

        // Last row
        for (int j = 0; j < m; j++) {
            if (grid[n - 1][j] == 1 && !vis[n - 1][j]) {
                dfs(n - 1, j, grid, vis, drow, dcol, ans);
            }
        }

        // First column
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 1 && !vis[i][0]) {
                dfs(i, 0, grid, vis, drow, dcol, ans);
            }
        }

        // Last column
        for (int i = 0; i < n; i++) {
            if (grid[i][m - 1] == 1 && !vis[i][m - 1]) {
                dfs(i, m - 1, grid, vis, drow, dcol, ans);
            }
        }

        // Count remaining 1s
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (ans[i][j] == 1) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};