class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int n = s.size();
        if (n == 0 || n <= k) {
            return n;
        } else if (k <= 0) {
            return 0;
        }
        unordered_map<char, list<pair<char,int>>::iterator> m;
        list<pair<char,int>> l;
        int max_len = 0, j = 0;
        for (int i = 0 ; i < n; i ++) {
            char x = s[i];
            if (m.count(x)) {
                auto pi = m[x];
                pair<char,int> p = *pi;
                m.erase(x);
                l.erase(pi);
            } else {
                if ((int) m.size() == k) {
                    pair<char,int> p = l.front();
                    m.erase(p.first);
                    l.pop_front();
                    max_len = max(max_len, i-j);
                    j = p.second+1;
                }
            }
            l.push_back(make_pair(x,i));
            m[x] = prev(l.end());
        }
        max_len = max(max_len, n-j);
        return max_len;
    }
};
