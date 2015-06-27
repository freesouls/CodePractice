class Solution {
public:
    // TODO: one dimensional array, O(N) space
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
         if (dungeon.size() == 0 ||dungeon[0].size() == 0) return 0;
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int> > health(dungeon.size(), vector<int>(dungeon[0].size()));
        health[m - 1][n - 1] = max(1, 1 - dungeon[m - 1][n - 1]);

        for (int i = n - 2; i >=0; --i) {
            health[m - 1][i] = max(1, health[m - 1][i + 1] - dungeon[m - 1][i]);
        }
        for (int i = m - 2; i >=0; --i) {
            health[i][n - 1] = max(1, health[i + 1][n - 1] - dungeon[i][n - 1]);
        }

        for (int i = m -2; i >= 0; --i) {
            for (int j = n -2; j >= 0; --j) {
                int right = max(1, health[i][j + 1] - dungeon[i][j]);
                int down  = max(1, health[i + 1][j] - dungeon[i][j]);
                health[i][j] = min(right, down);
            }
        }
        return health[0][0];
    }
};
