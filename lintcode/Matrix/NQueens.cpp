class Solution {
public:
    /**
     * Get all distinct N-Queen solutions
     * @param n: The number of queens
     * @return: All distinct solutions
     * For example, A string '...Q' shows a queen on forth position
     */


    vector<vector<string> > solveNQueens(int n) {
        // write your code here
        vector<vector<string> > res;
        vector<string> sol(n, string(n, '.'));
        vector<int> rows(n, -1);
        vector<int> cols(n, 0);
        dfs(res, sol, rows, cols, 0, n);
        return res;
    }

    void dfs(vector<vector<string> >& res, vector<string>& sol, vector<int>& rows, vector<int>& cols, int row, int n) {
        if (row == n) {
            res.push_back(sol);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (cols[i] == 0) {
                bool flag = true;
                for (int j = 0; j < row; j++) {
                    if (abs(rows[j] - i) == abs(j - row)) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    rows[row] = i;
                    cols[i] = 1;
                    sol[row][i] = 'Q';
                    dfs(res, sol, rows, cols, row+1, n);
                    rows[row] = -1;
                    cols[i] = 0;
                    sol[row][i] = '.';
                }
            }
        }
    }

};
