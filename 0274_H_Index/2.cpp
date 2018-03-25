class Solution {
public:
    // O(n) time and O(1) space
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int l = 0, r = n-1;
        int ans = 0;
        while (l <= r) {
            int pivot = citations[r];
            int i = l, j = l;
            for ( ; i < r ; i++) {
                if (citations[i] < pivot) {
                    swap(citations[i], citations[j++]);
                }
            }
            swap(citations[j], citations[r]);
            ans = max(ans, min(pivot, n-j));
            if (pivot > n-j) {
                r = j-1;
            } else if (pivot < n-j) {
                l = j+1;
            } else {
                break;
            }
        }
        return ans;
    }
};
