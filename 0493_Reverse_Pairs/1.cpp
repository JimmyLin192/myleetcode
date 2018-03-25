class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return reversePairsHelper(nums, 0, n);
    }
    int reversePairsHelper(vector<int>& nums, int left, int right) {
        if (left >= right - 1) {
            return 0;
        }
        int mid = left + (right - left) / 2;
        int ans = reversePairsHelper(nums, left, mid) + reversePairsHelper(nums, mid, right);
        for (int i = left, j = mid ; i < mid ; i++ ) {
            long a = 0L + nums[i];
            long b = 2L * nums[j];
            while (j < right && a > b) {
                b = 2L * nums[++j]; 
            }
            ans += j - mid;
        }
        inplace_merge(nums.begin()+left, nums.begin()+mid, nums.begin()+right);
        return ans;
    }
};
