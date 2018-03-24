class Solution {
public:
    // O(log(n) + k) Time Complexity, O(k) space complexity
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        if (k == 0) {
            return {};
        }
        if (x <= arr.front()) {
            return vector<int> (arr.begin(), arr.begin()+k);
        } else if (x >= arr.back()) {
            return vector<int>(arr.begin()+n-k, arr.end());
        }
        int l = 0, r = n-1;
        while (l < r - 1) {
            int mid = l + (r - l) / 2;
            if (arr[mid] > x) {
                r = mid;
            } else if (arr[mid] < x) {
                l = mid;
            } else {
                l = (r = mid);
            }
        }
        l == r ? r++ : 0;
        while (k--) {
            if (l < 0 || r >= n) {
                r >= n ? l-- : r++;
            } else {
                int l_dist = x - arr[l], r_dist = arr[r] - x;
                l_dist <= r_dist ? l-- : r++;
            }
        }
        return vector<int>(arr.begin()+l+1, arr.begin()+r);
    }
};
