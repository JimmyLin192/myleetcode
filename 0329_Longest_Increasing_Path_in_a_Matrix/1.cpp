class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) {
            return 0;
        }
        int m = matrix.front().size();
        if (m == 0) {
            return 0;
        }
        int ans = 0; 
        vector<vector<int>> memo (n, vector<int>(m, 0));
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                ans = max( ans , helper(i, j, memo, matrix) );
            }
        }
        return ans;
    }

    int helper(int i, int j, vector<vector<int>>& memo, vector<vector<int>>& matrix) {
        if (memo[i][j] > 0) {
            return memo[i][j];
        }
        int ans = 1;
        for (auto& dxdy : directions) {
            int x = i + dxdy.first, y = j + dxdy.second;
            if (x >= 0 && y >= 0 && x < matrix.size() && y < matrix.front().size()) {
                if (matrix[x][y] > matrix[i][j]) {
                    ans = max( ans, 1 + helper(x, y, memo, matrix) );
                }
            }
        }
        memo[i][j] = ans;
        return ans;
    }

    vector<pair<int,int>> directions = { {-1, 0}, {+1, 0}, {0, -1}, {0, +1} };

};

