class Solution {
public:
    int longest_count;
    int m;
    int n;
    vector<vector<int> > cache;
public:
    int longestIncreasingPath(vector<vector<int> >& matrix) {
        longest_count = 0;
        m = matrix.size();
        if (m == 0) {
            return 0;
        }
        n = matrix[0].size();
        if (n == 0) {
            return 0;
        }
        cache.resize(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++) {
                cache[i][j] = helper(matrix, 0, true, i, j);

                longest_count = std::max(longest_count, cache[i][j]);
            }
        }
        return longest_count;
    }
    // version 1: find increasing path
    int helper(vector<vector<int> >& matrix, int pre, bool pre_null, int i, int j) {
        if ( i < 0 || i >= m || j < 0 || j >= n) {
            return 0;
        }

        if (pre_null == false && pre >= matrix[i][j]) {
            return 0;
        }

        if (cache[i][j] != 0) {
            return cache[i][j];
        }

        int upper = helper(matrix, matrix[i][j], false, i-1, j);
        int down = helper(matrix, matrix[i][j], false, i+1, j);
        int left = helper(matrix, matrix[i][j], false, i, j-1);
        int right = helper(matrix, matrix[i][j], false, i, j+1);
        cache[i][j] = std::max(std::max(upper, down), std::max(left, right)) + 1;

        return cache[i][j];
    }
    // version 2: find decreasing path
    int helper(vector<vector<int> >& matrix, int pre, bool pre_null, int i, int j) {
        if ( i < 0 || i >= m || j < 0 || j >= n) {
            return 0;
        }

        if ( (pre_null == false && pre > matrix[i][j]) || pre_null == true ){
            if (cache[i][j] != 0) {
                return cache[i][j];
            }
            int upper = helper(matrix, matrix[i][j], false, i-1, j);
            int down = helper(matrix, matrix[i][j], false, i+1, j);
            int left = helper(matrix, matrix[i][j], false, i, j-1);
            int right = helper(matrix, matrix[i][j], false, i, j+1);
            cache[i][j] = std::max(std::max(upper, down), std::max(left, right)) + 1;
            return cache[i][j];
        }
        else {
            return 0;
        }
    }

};
