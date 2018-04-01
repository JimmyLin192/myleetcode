class Solution {
public:
    void subsetsHelper(vector<int>& nums, int index, vector<int>& cur, vector<vector<int>>& ans) {
        if (index == (int) nums.size()) {
            ans.push_back(cur);
            return;
        }
        subsetsHelper(nums, index+1, cur, ans);
        cur.push_back(nums[index]);
        subsetsHelper(nums, index+1, cur, ans);
        cur.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        subsetsHelper(nums, 0, cur, ans);
        return ans;
    }
};
