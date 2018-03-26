class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int N) {
        int n = picture.size();
        if (!n) {
            return 0;
        }
        int m = picture.front().size();
        if (!m) {
            return 0;
        }
        vector<int> r (n, 0); 
        vector<vector<int>> c (m, vector<int>());
        unordered_map<string, vector<int>> mp;
        vector<string> pict;
        for (int i = 0 ; i < n; i ++) { 
            string s = "";
            for (int j = 0 ; j < m; j ++) {
                if (picture[i][j] == 'B') {
                    r[i] ++;
                    c[j].push_back(i);
                }
                s += picture[i][j];
            }
            pict.push_back(s);
            if (mp.count(s)) {
                mp[s].push_back(i);   
            } else {
                mp[s] = {i};
            }
        }
        int ans = 0;
        for (int i = 0 ; i < n; i ++) { 
            for (int j = 0 ; j < m; j ++) {
                ans += picture[i][j] == 'B' && r[i] == N && r[i] == c[j].size() && c[j] == mp[pict[i]] ? 1 : 0;
            }
        }
        return ans;
    }
};
