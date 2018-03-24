class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool first_row_set = false, first_col_set = false;
        int n = matrix.size();
        if (n == 0) {
            return ;
        }
        int m = matrix.front().size();
        if (m == 0) {
            return ;
        }
        for (int j = 0; j < m; j ++) {
            if (matrix[0][j] == 0) {
                first_row_set = true;
            }
        }
        for (int i = 0; i < n; i ++) {
            if (matrix[i][0] == 0) {
                first_col_set = true;
            }
        }
        for (int i = 1; i < n; i ++) {
            for (int j = 1; j < m; j ++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < n; i ++) {
            for (int j = 1; j < m; j ++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (first_row_set) {
            for (int j = 0; j < m; j ++) {
                matrix[0][j] = 0;
            }
        }
        if (first_col_set) {
            for (int i = 0; i < n; i ++) {
                matrix[i][0] = 0;
            }
        }
    }
};
