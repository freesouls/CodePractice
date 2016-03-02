class Solution {
public:
    /**
     * @param grid a boolean 2D matrix
     * @return an integer
     */
    int numIslands(vector<vector<bool>>& grid) {
        // Write your code here
        if (grid.size() == 0 || grid[0].size() == 0) {
            return 0;
        }
        int count = 0;
        vector<vector<int> > sets;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                sets[i][j] = grid[i][j]? 1: 0;
            }
        }

        for (int i = 0; i < sets.size(); i++) {
            for (int j = 0; j < sets[0].size(); j++) {
                if (sets[i][j] == 1) {
                    dfs(i, j, sets);
                    ++count;
                }
            }
        }
        return count;
    }

    void dfs(int i, int j, vector<vector<int> > & grid) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) {
            return;
        }

        if (grid[i][j] == 1) {
            grid[i][j] = 2;
            dfs(i+1, j, grid);
            dfs(i-1, j, grid);
            dfs(i, j-1, grid);
            dfs(i, j+1, grid);
        }
    }
};
