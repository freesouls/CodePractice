class Solution {
public:
    int uniquePaths(int m, int n) {
        if (n <= 0  || m <= 0) return 0;
        vector<int> count(n, 1);
        for (int i = 1; i < m; i++){
            for (int j = 1; j < n; j++){
                count[j] += count[j-1];
            }
        }
        
        return count[n-1];
    }
};