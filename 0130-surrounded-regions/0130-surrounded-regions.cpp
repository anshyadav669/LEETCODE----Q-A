class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& vis,
             vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vis[row][col] = 1;
         vector<int> drow = {-1, 0, 1, 0};
        vector<int> dcol = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if (nrow < n && nrow>=0 && ncol>=0 && ncol<m && board[nrow][ncol] == 'O' && !vis[nrow][ncol]){
                dfs(nrow,ncol,vis,board);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector(m, 0));

        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O') {
                dfs(0,j,vis,board);
            }
        }
        for (int j = 0; j < m; j++) {
            if (board[n - 1][j] == 'O') {
                dfs(n-1,j,vis,board);
            }
        }
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') {
                dfs(i,0,vis,board);
            }
        }
        for (int i = 0; i < n; i++) {
            if (board[i][m - 1] == 'O') {
                dfs(i,m-1,vis,board);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j] == 0){
                    board[i][j] = 'X';
                }
            }
        }
    }
};