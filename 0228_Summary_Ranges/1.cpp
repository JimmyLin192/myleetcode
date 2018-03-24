class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        if (!n) {
            return {};
        }
        vector<string> ans;
        int left = 0;
        for (int right = 1; right <= n; right ++) {
            if (right == n || nums[right] > nums[right-1] + 1) {
                ans.push_back(to_string(nums[left]) + (left==right-1?"":("->" + to_string(nums[right-1]))));
                left = right;
            }
        }
        return ans;
    }
};
