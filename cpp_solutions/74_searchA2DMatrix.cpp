// TODO: Binary Search
class Solution {
public:
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
