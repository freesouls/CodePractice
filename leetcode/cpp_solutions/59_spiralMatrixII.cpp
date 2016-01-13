class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if (n <= 0){
            vector<vector<int>> res;
            return res;
        }
        vector<int> vec(n, 0);
        vector<vector<int>> res(n, vec);

        int beginX = 0;
        int endX = n - 1;
        int beginY = 0;
        int endY = n - 1;
        // res.resize((end+1)*(endY+1));
        int count = 1;
        while(true){
            for(int i = beginX; i <= endX; i++){
                res[beginY][i]=count++;
                // res.push_back(matrix[beginY][i]);
            }
            if((++beginY) > endY){
                break;
            }
            for(int i = beginY; i <= endY; i++){
                res[i][endX]=count++;
                // res.push_back(matrix[i][endX]);
            }
            if((--endX) < beginX){
                break;
            }
            for(int i = endX; i >= beginX; i--){
                res[endY][i]=count++;
                // res.push_back(matrix[endY][i]);
            }
            if((--endY) < beginY){
                break;
            }
            for(int i = endY; i >= beginY; i--){
                res[i][beginX]=count++;
                // res.push_back(matrix[i][beginX]);
            }
            if((++beginX) > endX){
                break;
            }
        }
        return res;
    }
};
