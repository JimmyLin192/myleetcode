class Solution {
public:

    vector<pair<int,int>> directions = { {+1, 0}, {-1, 0}, {0, -1}, {0, +1} };
    
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if (n == 0) {
            return ;
        }
        int m = board[0].size();
        if (m == 0) {
            return ;
        }
        for (int i = 0; i < n; i ++) {
            dfs(board, i, 0);
            dfs(board, i, m-1);
        }
        for (int j = 1; j < m-1; j ++) {
            dfs(board, 0, j);
            dfs(board, n-1, j);
        }
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == 'B') {
                    board[i][j] = 'O';
                }
            }
        }
        return ;
    }
    void dfs(vector<vector<char>>& board, int i, int j) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) {
            return ;
        } else if (board[i][j] == 'B') {
            return ;
        } else if (board[i][j] == 'X') {
            return ;
        }
        board[i][j] = 'B';
        for (auto& dir : directions) {
            dfs(board, i + dir.first, j + dir.second);
        }
        return ;
    }

};

