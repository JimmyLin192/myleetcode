class Solution {
public:
    bool isValidSudokuHelper(vector<vector<char>>& board, int il, int ir, int jl, int jr) {
        vector<int> occupied (9, 0);
        for (int i = il; i < ir; i ++) {
            for (int j = jl; j < jr; j ++) {
                if (board[i][j] == '.') {
                    continue;
                }
                int val = board[i][j]-'1';
                if (occupied[val]) {
                    return false;
                } else {
                    occupied[val] = 1;
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        if (!n) {
            return true;
        }
        int m = board.front().size();
        if (!m) {
            return true;
        }
        for (int i = 0 ; i < n ; i ++) {
            if (!isValidSudokuHelper(board, i, i+1, 0, m)) {
                return false;
            }
        }
        for (int j = 0 ; j < m ; j ++) {
            if (!isValidSudokuHelper(board, 0, n, j, j+1)) {
                return false;
            }
        }
        for (int i = 0 ; i < n ; i += 3) {
            for (int j = 0; j < m ; j += 3) {
                if (!isValidSudokuHelper(board, i, i+3, j, j+3)) {
                    return false;
                }
            }
        }
        return true;
    }
};
