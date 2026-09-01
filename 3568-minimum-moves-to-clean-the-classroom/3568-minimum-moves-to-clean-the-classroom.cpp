class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sr = 0, sc = 0;
        int k = 0;

        vector<vector<int>> id(m, vector<int>(n, -1));

        // Find S and assign IDs to L
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }

                if (classroom[i][j] == 'L') {
                    id[i][j] = k++;
                }
            }
        }

        int fullMask = (1 << k) - 1;

        // {row, col, remainingEnergy, mask}
        queue<array<int, 4>> q;

        q.push({sr, sc, energy, 0});

        // visited[row][col][energy][mask]
        vector<vector<vector<vector<bool>>>> visited(
            m,
            vector<vector<vector<bool>>>(
                n,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(1 << k, false)
                )
            )
        );

        visited[sr][sc][energy][0] = true;

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        int moves = 0;

        while (!q.empty()) {

            int sz = q.size();

            while (sz--) {

                auto [r, c, e, mask] = q.front();
                q.pop();

                // All litter collected
                if (mask == fullMask)
                    return moves;

                for (int d = 0; d < 4; d++) {

                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    // Outside grid
                    if (nr < 0 || nr >= m ||
                        nc < 0 || nc >= n)
                        continue;

                    // Obstacle
                    if (classroom[nr][nc] == 'X')
                        continue;

                    // No energy to make a move
                    if (e == 0)
                        continue;

                    int ne = e - 1;
                    int nmask = mask;

                    // Collect litter
                    if (classroom[nr][nc] == 'L') {
                        int bit = id[nr][nc];
                        nmask |= (1 << bit);
                    }

                    // Reset energy
                    if (classroom[nr][nc] == 'R') {
                        ne = energy;
                    }

                    if (!visited[nr][nc][ne][nmask]) {

                        visited[nr][nc][ne][nmask] = true;

                        q.push({
                            nr,
                            nc,
                            ne,
                            nmask
                        });
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};