// TODO: Binary Search
class Solution {
public:
    // treat the matrix as a one-dim vector with elements ascending
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0){
            return false;
        }

        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0;
        int right = m*n-1;
        while(left <= right) {
            int middle = (left+right)/2;
            int i = middle/n;
            int j = middle%n;
            if (matrix[i][j] < target) {
                left = middle+1;
            }
            else if (matrix[i][j] > target) {
                right = middle-1;
            }
            else{
                return true;
            }
        }

        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int up = 0, bottom = m - 1;
        int left = 0, right = n - 1;
        int i = 0;
        for (; i < m; i++){
            if (target == matrix[i][0]){
                return true;
            }
            if (target < matrix[i][0]){
                break;
            }
        }
        if (i == 0){
            return false;
        }

        i--;

        int j = 1;
        for (; j < n; j++){
            if (target == matrix[i][j]){
                return true;
            }
        }
        return false;
    }
};
