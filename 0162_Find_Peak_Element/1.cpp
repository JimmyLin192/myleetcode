class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int ans = -1;
        for (int i = 0; i < n; i ++) {
            if ( (i == 0 || nums[i] > nums[i-1]) && (i == n-1 || nums[i] > nums[i+1]) ) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};
