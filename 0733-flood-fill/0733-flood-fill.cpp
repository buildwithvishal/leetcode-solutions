class Solution {
public:
    void dfs(vector<vector<int>>& image, vector<vector<int>>& ans, int sr, int sc, int color, int initialColor) {

        int m = image.size();
        int n = image[0].size();

        ans[sr][sc] = color;

        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int nrow = sr + delrow[i];
            int ncol = sc + delcol[i];

            if (nrow >= 0 && nrow < m &&
                ncol >= 0 && ncol < n &&
                ans[nrow][ncol] != color &&
                image[nrow][ncol] == initialColor) {

                dfs(image, ans, nrow, ncol, color, initialColor);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int initialColor = image[sr][sc];

        if (initialColor == color)
            return image;

        vector<vector<int>> ans = image;

        dfs(image, ans, sr, sc, color, initialColor);

        return ans;
    }
};