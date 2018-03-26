class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (!n) {
            return {};
        }
        int m = matrix.front().size();
        if (!m) {
            return {};
        }
        vector<vector<int>> pacific (n, vector<int>(m, 0)), atlantic (n, vector<int>(m, 0));
        for (int j = 0 ; j < m ; j ++) {
            dfs(matrix, 0, j, pacific);
            dfs(matrix, n-1, j, atlantic);
        }
        for (int i = 0 ; i < n ; i ++) {
            dfs(matrix, i, 0, pacific);
            dfs(matrix, i, m-1, atlantic);
        }
        vector<pair<int,int>> ans;
        for (int i = 0 ; i < n ; i ++) {
            for (int j = 0 ; j < m ; j ++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    ans.push_back(make_pair(i, j));
                }
            }
        }
        return ans;
    }
    void dfs(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& visited) {
        if (visited[i][j]) {
            return;
        }
        visited[i][j] = 1;
        for (auto d : directions) {
            int ni = i + d.first, nj = j + d.second;
            if (ni < 0 || nj < 0 || ni >= matrix.size() || nj >= matrix.front().size() || visited[ni][nj]) {
                continue;
            } else if (matrix[ni][nj] >= matrix[i][j]) {
                dfs(matrix, ni, nj, visited);   
            }
        }
    }
private: 
    vector<pair<int,int>> directions = {{-1, 0}, {+1, 0}, {0, -1}, {0, +1}};
};
