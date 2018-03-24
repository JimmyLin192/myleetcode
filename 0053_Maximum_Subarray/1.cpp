class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if (!n) {
            return 0;
        }
        int min_sum = 0, ans = INT_MIN, sum = 0;
        for (int i = 0 ; i < n ; i ++) {
            sum += nums[i];
            ans = max(ans, sum - min_sum);
            min_sum = min (min_sum, sum);
        }
        return ans;
    }
};
