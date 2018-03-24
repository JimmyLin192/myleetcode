class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> freq(3, 0);
        for (int num : nums) {
            freq[num] ++;
        }
        int write_index = 0;
        for (int i = 0 ; i < 3; i ++) {
            while (freq[i] -- > 0) {
                nums[write_index++] = i;
            }
        }
    }
};
