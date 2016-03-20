class Solution {
public:
    /**
     * @param board a 2D board containing 'X' and 'O'
     * @return void
     */
    void surroundedRegions(vector<vector<char>>& board) {
        // Write your code here
        if (board.size() <= 2 || board[0].size() <= 2 ) {
            return;
        }
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') {
                dfs(board, i, 0);
            }

            if (board[i][n-1] == 'O') {
                dfs(board, i, n-1);
            }
        }

        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') {
                dfs(board, 0, j);
            }

            if (board[m-1][j] == 'O') {
                dfs(board, m-1, j);
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                else if (board[i][j] == '1') {
                    board[i][j] = 'O';
                }
            }
        }
    }

    void dfs(vector<vector<char> > &matrix, int i, int j) {
        if ( i < 0 || j < 0 || i >= matrix.size() || j >= matrix[0].size()) {
            return;
        }

        if (matrix[i][j] == 'O') {
            matrix[i][j] = '1';
            dfs(matrix, i, j-1);
            dfs(matrix, i, j+1);
            dfs(matrix, i-1, j);
            dfs(matrix, i+1, j);
        }
    }
};
