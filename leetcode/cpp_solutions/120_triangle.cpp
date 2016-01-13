class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 0 || triangle[0].size() == 0){
            return 0;
        }
        int row = triangle.size();
        vector<int> f(row, 0);
        f[0] = triangle[0][0];
        for(int i = 1; i < row; i++){
            int tmp_start = f[0];
            int tmp_end = f[i-1];
            for(int j = i-1; j >= 1; j--){ //use (int j = 1; j < i; j++) is wrong,
                f[j] = min(f[j-1], f[j]) + triangle[i][j];
            }
            f[0] = tmp_start + triangle[i][0];
            f[i] = tmp_end + triangle[i][i];
        }

        int res = f[0];
        for(int i = 1; i < row; i++){
            if (f[i] < res){
                res = f[i];
            }
        }
        return res;
    }
};
