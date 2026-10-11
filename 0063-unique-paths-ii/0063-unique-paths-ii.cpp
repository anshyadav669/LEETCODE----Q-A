
class Solution {
public:
    vector<vector<int>> dp;

    int solve(int i, int j, int m, int n,
              vector<vector<int>>& obstacleGrid) {

        if (i >= m || j >= n || obstacleGrid[i][j] == 1) {
            return 0;
        }

        if (i == m - 1 && j == n - 1) {
            return 1;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int right = solve(i, j + 1, m, n, obstacleGrid);
        int down = solve(i + 1, j, m, n, obstacleGrid);

        return dp[i][j] = right + down;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        dp.assign(m, vector<int>(n, -1));

        if (obstacleGrid[0][0] == 1) {
            return 0;
        }

        return solve(0, 0, m, n, obstacleGrid);
    }
};
