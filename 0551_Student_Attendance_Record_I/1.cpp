class Solution {
public:
    bool checkRecord(string s) {
        int n = s.size();
        int num_absent = 0, num_cont_late = 0;
        for (char x : s) {
            if (x == 'A') {
                num_absent ++;
                num_cont_late = 0;
                if (num_absent > 1) {
                    return false;
                }
            } else if (x == 'L') {
                num_cont_late ++;
                if (num_cont_late > 2) {
                    return false;
                }
            } else if (x == 'P') {
                num_cont_late = 0;
            }
        }
        return true;
    }
};
