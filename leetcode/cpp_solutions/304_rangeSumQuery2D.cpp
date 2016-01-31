class NumMatrix {
    vector<vector<int> > sums;
    bool flag = false;
public:
    NumMatrix(vector<vector<int>> &matrix) {

        int m = matrix.size();
        if (m == 0) {
            return;
        }
        int n = matrix[0].size();
        if (n == 0) {
            return;
        }
        flag = true;
        sums.resize(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < m; i++) {
            int row_sum = 0;
            for (int j = 0; j < n; j++) {
                row_sum += matrix[i][j];
                sums[i+1][j+1] = sums[i][j+1] + row_sum;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if (flag) {
            return sums[row2+1][col2+1] - sums[row2+1][col1] - sums[row1][col2+1] + sums[row1][col1];
        }
        return 0;
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);
