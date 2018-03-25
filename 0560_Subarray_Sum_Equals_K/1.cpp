class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0, n = nums.size();
        unordered_map<long, int> sum_freq;
        long sum = 0;
        sum_freq[0L]++;
        for (int i = 0 ; i < n ; i ++) {
            sum += nums[i];
            long target = sum-k;
            if (sum_freq.count(target)) {
                ans += sum_freq[target];
            }
            sum_freq[sum]++;
        }
        return ans;
    }
};
