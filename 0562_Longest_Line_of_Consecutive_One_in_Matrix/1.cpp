class Solution {
public:
    vector<pair<int,int>> directions = {{+1, 0}, {0, +1}, {+1, +1}, {-1, +1}};
    int longestLine(vector<vector<int>>& M) {
        int n = M.size();
        if (!n) {
            return 0;
        }
        int m = M.front().size();
        if (!m) {
            return 0;
        }
        int ans = 0;
        for (int i = 0 ; i < n ; i ++) {
            for (int j = 0 ; j < m ; j ++) {
                if (!M[i][j]) {
                    continue;
                }
                for (auto d : directions) {
                    int pi = i - d.first, pj = j - d.second;
                    if (pi < 0 || pj < 0 || pi >= n || pj >= m || M[pi][pj] == 0) {
                        ans = max ( ans, search(M, d, i, j) );
                    }
                }
            }
        }
        return ans;
    }
    int search(vector<vector<int>>& M, pair<int,int>& d, int i, int j) {
        int ans = 0;
        int n = M.size(), m = M.front().size();
        while (i >= 0 && j >= 0 && i < n && j < m && M[i][j]) {
            ans ++;
            i += d.first, j += d.second;
        }
        return ans;
    }
};
