class Solution {
public:
    string customSortString(string S, string T) {
        vector<int> freq (26, 0);
        int m = S.size(); 
        int n = T.size();
        for (int i = 0; i < n; i ++) {
            freq[T[i]-'a']++;
        }
        int write_index = 0;
        for (int j = 0; j < m; j ++) {
            int cur_idx = S[j] - 'a';
            while (freq[cur_idx] > 0) {
                T[write_index++] = 'a' + cur_idx;
                freq[cur_idx]--;
            }
        }
        for (int k = 0; k < 26; k ++) {
            while (freq[k] > 0) {
                T[write_index++] = 'a' + k;
                freq[k]--;
            }
        }
        return T;
    }
};
