class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0){
            return false;
        }
        
        int m = matrix.size();
        int n = matrix[0].size();
        //int i = 0;
        
        for (int i = 0; i < m; i++){
            if (target < matrix[i][0]){
                return false;
            }
            
            if (target > matrix[i][n-1]){
                continue;
            }
            
            int left = 0;
            int right = n-1;
            
            while(left <= right){
                int middle = (left+right) >> 1; // (left + right)/2
                if (matrix[i][middle]> target){
                    right = middle - 1;
                    //continue;
                }
                else if(matrix[i][middle] < target){
                    left = middle + 1;
                }
                else{
                    return true;
                }
            }
        }
        return false;
    }
};