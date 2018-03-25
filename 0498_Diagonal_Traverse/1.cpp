class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (!n) {
            return {};
        }
        int m = matrix.front().size();
        if (!m) {
            return {};
        }
        int total = n * m;
        vector<int> ans;
        vector<pair<int,int>> directions = { {-1,+1} , {+1,-1} };
        int i = 0, j = 0;
        auto diter = directions.begin();
        while (ans.size() < total) {
            ans.push_back(matrix[i][j]);
            int ni = i + diter->first, nj = j + diter->second;
            if (ni < 0 || nj < 0 || ni >= n || nj >= m) {
                if (++diter == directions.end()) {
                    diter = directions.begin();
                }
                if (i == n-1) {
                    ni = i, nj = j + 1;
                } else if (j == m-1) {
                    ni = i + 1, nj = j;
                } else if (i == 0) {
                    ni = i, nj = j + 1;
                } else if (j == 0) {
                    ni = i + 1, nj = j;
                }
            }
            i = ni, j = nj;
        }
        return ans;
    }
};
