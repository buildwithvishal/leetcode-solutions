class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int m, int n,
             int drow[], int dcol[], int row, int col) {

        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                !vis[nrow][ncol] && grid[nrow][ncol] == 1) {

                vis[nrow][ncol] = 1;
                dfs(grid, vis, m, n, drow, dcol, nrow, ncol);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        int drow[4] = {0, 1, 0, -1};
        int dcol[4] = {-1, 0, 1, 0};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (i == 0 || j == 0 || i == m - 1 || j == n - 1) {

                    if (grid[i][j] == 1 && !vis[i][j]) {
                        vis[i][j] = 1;
                        dfs(grid, vis, m, n, drow, dcol, i, j);
                    }
                }
            }
        }

        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 1 && !vis[i][j]) {
                    count++;
                }
            }
        }

        return count;
    }
};