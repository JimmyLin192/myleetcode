class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int n = nums.size();
        if (n < 3) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < n - 2; i ++) {
            int j = i + 1, k = n - 1;
            long lt = 0L + target - nums[i];
            while (j < k) {
                long tsum = 0L + nums[j] + nums[k];
                if (tsum < lt) {
                    ans += k - j;
                    j ++;
                } else {
                    k--;
                }
            }
        }
        return ans;
    }
};
