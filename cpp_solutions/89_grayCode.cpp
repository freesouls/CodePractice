class Solution {
public:
    vector<int> grayCode(int n) {
        int size =  1 << n;
        vector<int> res(size, 0);
        for (int i = 0; i < size; i++){
            res[i] = i^(i >> 1);
        }
        return res;
    }
};
