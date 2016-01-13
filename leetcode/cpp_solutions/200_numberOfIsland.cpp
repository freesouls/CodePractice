class Solution {
public:
    int m;
    int n;

    int numIslands(vector<vector<char>>& board) {
        if (board.size()==0 || board[0].size() == 0){
            return 0;
        }
        m = board.size();
        n = board[0].size();
        int res = 0;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (board[i][j] == '1'){
                    res++;
                    traverse(board, i, j);
                }
            }
        }
        return res;
    }

    void traverse(vector<vector<char>>& board, int i, int j){
        // if (i <0 || i >= m || j <0 || j >= n){
        //     return;
        // }
        // else{
            if (board[i][j] == '1'){
                board[i][j] = '2';
                if (i > 0) traverse(board, i-1, j);
                if (i < m-1) traverse(board, i+1, j);
                if (j > 0) traverse(board, i, j-1);
                if (j < n-1) traverse(board, i, j+1);
            }
        // }
    }
};
