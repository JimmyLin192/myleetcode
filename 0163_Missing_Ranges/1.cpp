class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<string> ans;
        int first = n;
        for (int i = 0 ; i < n ; i ++) {
            if (nums[i] >= lower) {
                first = i;
                break;
            }
        }
        if (first == n) {
            string r = getRange(lower-1L, upper+1L);
            if (!r.empty()) {
                ans.push_back(r);
            }
            return ans;
        }
        long prev = lower-1L;
        for (int i = first; i <= n ; i ++) {
            string r = "";
            if (i == n || nums[i] > upper) {
                r = getRange(prev, upper+1L); 
            } else { // i < n
                r = getRange(prev, (long) nums[i]);
            }
            if (!r.empty()) {
                ans.push_back(r);
            }
            if (nums[i] > upper) {
                break;
            }
            prev = nums[i];
        }
        return ans;
    }
    string getRange(long left, long right) {
        if (left >= right - 1) {
            return "";
        } else if (left + 1 == right -1) {
            return to_string(right-1);
        } else { // left + 1 < right - 1
            return to_string(left+1) + "->" + to_string(right-1);
        }
    }
};
