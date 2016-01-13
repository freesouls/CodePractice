class Solution {
public:
    vector<vector<string> > res;
    vector<int> cols;
    vector<int> rows;
    vector<string> sol;
    vector<vector<string>> solveNQueens(int n) {
        // queens should be not at the same row, col, diagnal or anti-diagnal
        res.clear();
        sol.clear();
        string tmp(n, '.');
        cols.resize(n, -1);
        rows.resize(n, -1);
        for(int i = 0; i < n; i++){
            sol.push_back(tmp);
        }
        solve(0, n);
        return res;
    }

    void solve(int row, int n){
        if (row == n){
            res.push_back(sol);
        }
        for (int j = 0; j < n; j++) {
            if (cols[j] == -1){
                bool flag = true;
                for (int i = 0; i < row; i++){
                    // check if is at the same diagnal or anti-diagnal
                    if(abs(i - row) == abs(j-rows[i])){
                        flag = false;
                        break;
                    }
                }
                if (flag){
                    sol[row][j] = 'Q';
                    cols[j] = j;
                    rows[row] = j;
                    solve(row + 1, n);
                    sol[row][j] = '.';
                    cols[j] = -1;
                    rows[row] = -1;
                }
            }
        }
    }
};
