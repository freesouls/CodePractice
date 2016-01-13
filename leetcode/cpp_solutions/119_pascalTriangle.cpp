class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex+1, 1);
        for (int i = 1; i <rowIndex+1; i++){
            int pre = res[0];
            for (int j = 1; j <= i-1; j++){
                int tmp = res[j];
                res[j] += pre;
                pre = tmp;
            }
        }
        return res;
    }
};
