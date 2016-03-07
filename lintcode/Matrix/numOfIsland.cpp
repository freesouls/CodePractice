class Solution {
public:
    /**
     * @param grid a boolean 2D matrix
     * @return an integer
     */
    int numIslands(vector<vector<bool>>& grid) {
        // Write your code here
        if (grid.size() == 0 || grid[0].size() == 0 ){
            return 0;
        }
        int cnt = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j]) {
                    dfs(grid, i, j);
                    cnt++;
                }
            }
        }
        return cnt;
    }

    void dfs(vector<vector<bool>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j>=grid[0].size()) {
            return ;
        }

        if(grid[i][j]){
            grid[i][j] = false;
            dfs(grid, i, j+1);
            dfs(grid, i, j-1);
            dfs(grid, i-1, j);
            dfs(grid, i+1, j);
        }
    }
};
