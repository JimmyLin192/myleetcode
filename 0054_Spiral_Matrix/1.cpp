class Solution {
public:
    vector<pair<int,int>> directions = {
        {0, +1}, {+1, 0}, {0, -1}, {-1, 0}
    };
    vector<vector<int>> bdirections = {
        {0, 0, +1, 0},
        {0, -1, 0, 0},
        {0, 0, 0, -1},
        {+1, 0, 0, 0},
    };
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) {
            return {};
        }
        int m = matrix[0].size();
        if (m == 0) {
            return {};
        }
        int write_index = 0, total = n * m; 
        vector<int> ans (total, 0);
        int l = 0, r = m-1, t = 0, b = n-1;
        int i = 0, j = 0;
        auto d = directions.begin();
        auto bd = bdirections.begin();
        while (write_index < total) {
            ans[write_index++] = matrix[i][j];
            int ni = i + d->first, nj = j + d->second;
            if (ni < t || ni > b || nj < l || nj > r) {
                if (++d == directions.end()) {
                    d = directions.begin();
                }
                ni = i + d->first, nj = j + d->second;
                l += (*bd)[0], r += (*bd)[1], t += (*bd)[2], b += (*bd)[3];
                if (++bd == bdirections.end()) {
                    bd = bdirections.begin();
                }
            }
            i = ni, j = nj; 
        }
        return ans;
    }
};
