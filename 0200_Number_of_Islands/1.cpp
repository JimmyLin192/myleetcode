class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int n = grid.size();
        if (n == 0) {
            return ans;
        }
        int m = grid[0].size();
        if (m == 0) {
            return ans;
        }
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (grid[i][j] == '1') {
                    ans++;
                    dfs(grid, i, j);
                }
            }
        }
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                grid[i][j] = grid[i][j] == '2' ? '1' : grid[i][j];
            }
        }
        return ans;
    }
    void dfs (vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) {
            return ;
        }
        if (grid[i][j] == '1') {
            grid[i][j] = '2';
        } else {
            return ;
        } 
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }
};

