class Solution {
public:
    long MOD_VAL = 1000000007;
    // O(n) time complexity, O(1) space complexity
    int checkRecord(int n) {
        if (n <= 0) {
            return 0;
        } else if (n == 1) {
            return 3;
        }
        vector<vector<long>> R (2, vector<long>(3, 0));
        R[0][0] = 1;
        R[0][1] = 1;
        R[1][0] = 1;
        for (int k = 2; k <= n; k ++) {
            vector<vector<long>> Rn (2, vector<long>(3, 0));
            Rn[0][0] = (R[0][0] + R[0][1] + R[0][2]) % MOD_VAL;
            Rn[0][1] = R[0][0];
            Rn[0][2] = R[0][1];
            Rn[1][0] = (R[0][0] + R[0][1] + R[0][2] + 
                       R[1][0] + R[1][1] + R[1][2]) % MOD_VAL;
            Rn[1][1] = R[1][0];
            Rn[1][2] = R[1][1];
            R = Rn;
        }
        long ans = 0;
        for (int i = 0; i < 2; i ++) {
            for (int j = 0; j < 3; j ++) {
                ans += R[i][j];
            }
        }
        return (int) (ans % MOD_VAL);
    }
};
