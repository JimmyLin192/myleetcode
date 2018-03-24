class Solution {
public:
    string crackSafe(int n, int k) {
        string ans = string(n, '0');
        unordered_set<string> s;
        s.insert(ans);
        int total = pow(k, n);
        for (int i = 0; i < total; i ++) {
            string base = ans.substr(ans.size()-(n-1), n-1);
            for (int j = k-1; j >= 0; j --) {
                string str = base + to_string(j);
                if (!s.count(str)) {
                    s.insert(str);
                    ans += to_string(j);
                    break;
                }
            }
        }
        return ans;
    }
};
