class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<int> dist (m+1, 0);
        for (int j = 0; j <= m; j ++) {
            dist[j] = j;
        }
        for (int i = 1; i <= n; i ++) {
            vector<int> next_dist (m+1, 0);
            next_dist[0] = i;
            for (int j = 1; j <= m; j ++) {
                next_dist[j] = min(word1[i-1]==word2[j-1]?dist[j-1]:INT_MAX, 
                              min(next_dist[j-1]+1, dist[j]+1));
            }
            dist = next_dist;
        }
        return dist.back();
    }
};
