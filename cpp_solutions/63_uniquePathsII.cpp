class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if (m == 0) return 0;
        int n = obstacleGrid[0].size();
        if (n == 0) return 0;

        vector<int> count(n, 1);
        bool flag = false;
        int k = 0;
        for (; k < n; k++){
            if (obstacleGrid[0][k]){
                break;
            }
        }
        
        for(int i = k; i < n; i++){
            count[i] = 0;
        }
        
        for (int i = 1; i < m; i++){
            if (obstacleGrid[i][0]){
                count[0] = 0;
            }
            for (int j = 1; j < n; j++){
                if (obstacleGrid[i][j]){
                    count[j] = 0;
                }
                else{
                    count[j] += count[j-1];
                }
            }
        }
        
        return count[n-1];
    }
};