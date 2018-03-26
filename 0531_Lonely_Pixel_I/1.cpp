class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int n = picture.size();
        if (!n) {
            return 0;
        }
        int m = picture.front().size();
        if (!m) {
            return 0;
        }
        vector<int> r (n, 0), c (m, 0);
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (picture[i][j] == 'B') {
                    r[i] ++, c[j] ++;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                ans += picture[i][j] == 'B' && r[i] == 1 && c[j] == 1 ? 1 : 0;
            }
        }
        return ans;
    }
};
