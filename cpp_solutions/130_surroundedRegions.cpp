class Solution {
public:
    long m = 0;
    long n = 0;
    void solve(vector<vector<char>>& board) {
        if (board.size()==0 || board[0].size() == 0){
            return;
        }
        m = board.size();
        n = board[0].size();

        for (long i = 0; i < m; i++){
            if (board[i][0] == 'O'){
                traverse(board, i, 0);
            }
            if (board[i][n-1] == 'O'){
                traverse(board, i, n-1);
            }
        }

        for (long i = 0; i < n; i++){
            if (board[0][i] == 'O'){
                traverse(board, 0, i);
            }
            if (board[m-1][i] == 'O'){
                traverse(board, m-1, i);
            }
        }

        for (long i = 0; i < m; i++){
            for (long j = 0; j < n; j++){
                if (board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                else if (board[i][j] == '1'){
                    board[i][j] = 'O';
                }
            }
        }
    }

    void traverse(vector<vector<char>>& board, long i, long j){
        // if (i <0 || i >= m || j <0 || j >= n){
        //     return;
        // }
        // else{
            if (board[i][j] == 'O'){
                board[i][j] = '1';
                if (i > 0) traverse(board, i-1, j);
                if (i < m-1) traverse(board, i+1, j);
                if (j > 0) traverse(board, i, j-1);
                if (j < n-1) traverse(board, i, j+1);
            }
        // }
    }
};
