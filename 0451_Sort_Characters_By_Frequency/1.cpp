class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        if (n <= 1) return s;
        vector<pair<int, char>> freq (256, make_pair(0, ' '));
        for (char x : s) {
            freq[x].first ++;
            freq[x].second = x;
        }
        sort(freq.begin(), freq.end(), [](pair<int,char> l, pair<int,char> r){ return l.first > r.first; });
        for (int i = 0, write_index = 0; write_index < n && i < 256; i++) {
            while (freq[i].first--) {
                s[write_index++] = freq[i].second;
            }
        }
        return s;
    }
};
