class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        string ans = "";
        int n = s.size();
        vector<int> b (n, 0);
        for (string& str : dict) {
            int m = str.size();
            for (int i = 0; i < n-m+1; i ++) {
                if (s.substr(i, m) == str) {
                    for (int k = i; k < i+m; k ++) {
                        b[k] = 1;
                    }
                }
            }
        }
        for (int i = 0 ; i < n ; i ++) {
            if ( (i == 0 || !b[i-1]) && b[i]) {
                ans += "<b>";
            } else if ( b[i-1] && !b[i] ) {
                ans += "</b>";
            }
            ans += s[i];
        }
        if (n > 0 && b.back()) {
            ans += "</b>";
        }
        return ans;
    }
};
