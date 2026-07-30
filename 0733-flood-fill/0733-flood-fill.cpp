class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();

        int initialcolor = image[sr][sc];
        if(initialcolor == color){
            return image;
        }

        queue<pair<int, int>> q;
        vector<vector<int>> ans;
        ans = image;
        ans[sr][sc] = color;
        q.push({sr, sc});

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i =0; i<4; i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && image[nrow][ncol] != color && ans[nrow][ncol] != color && image[nrow][ncol] == initialcolor){
                    ans[nrow][ncol] = color;
                    q.push({nrow, ncol});
                }
            }
        }


        return ans;
    }
};