class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0){
            return 0;
        }
        int m = grid.size();
        int n = grid[0].size();
        vector<int> f(n, 0);
        f[0] = grid[0][0];
        for (int i = 1; i < n; i++){
            f[i] = f[i-1] + grid[0][i];
        }

        for(int i = 1; i < m ; i++){
            f[0] = f[0] + grid[i][0];
            for(int j = 1; j < n; j++){
                f[j] =  min(f[j], f[j-1]) + grid[i][j];
            }
        }
        return f[n-1];
    }
};
