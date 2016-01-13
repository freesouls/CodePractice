class Solution {
public:
    vector<bool> cols;
    vector<int> rows;
    int res = 0;
    int totalNQueens(int n) {
        cols.resize(n, false);
        rows.resize(n, -1);
        solve(0, n);
        return res;
    }

    void solve(int row, int n){
        if (row == n){
            res++;
        }
        for (int j = 0; j < n; j++) {
            if (!cols[j]){ // check is at same column
                bool flag = true;
                for (int i = 0; i < row; i++){
                    // check if is at the same diagnal or anti-diagnal
                    if(abs(i - row) == abs(j-rows[i])){
                        flag = false;
                        break;
                    }
                }
                if (flag){
                    cols[j] = true;
                    rows[row] = j;
                    solve(row + 1, n);
                    cols[j] = false;
                    rows[row] = -1;
                }
            }
        }
    }
};
