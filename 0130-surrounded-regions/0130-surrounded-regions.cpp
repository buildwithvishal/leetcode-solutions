class Solution {
public:
    void dfs(vector<vector<char>>& board, vector<vector<int>>& vis,
             int m, int n, int drow[], int dcol[],
             int row, int col) {

        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if (nrow >= 0 && nrow < m &&
                ncol >= 0 && ncol < n &&
                !vis[nrow][ncol] &&
                board[nrow][ncol] == 'O') {

                vis[nrow][ncol] = 1;
                dfs(board, vis, m, n, drow, dcol, nrow, ncol);
            }
        }
    }

    void solve(vector<vector<char>>& board) {

        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        int drow[4] = {0, 1, 0, -1};
        int dcol[4] = {-1, 0, 1, 0};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (i == 0 || j == 0 || i == m - 1 || j == n - 1) {

                    if (board[i][j] == 'O' && !vis[i][j]) {
                        vis[i][j] = 1;
                        dfs(board, vis, m, n, drow, dcol, i, j);
                    }
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (board[i][j] == 'O' && !vis[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};