class Solution {
public:
    vector<vector<int>> res;
    int k_num;
    int target;
    vector<vector<int>> combinationSum3(int k, int n) {
        res.clear();
        vector<int> vec;
        k_num = k;
        target = n;
        combination(vec, 0, 0, 1);
        return res;
    }

    void combination(vector<int>& vec, int depth, int t, int index){
        if(depth == k_num && target ==  t){
            res.push_back(vec);
            return;
        }
        if (depth >= k_num){
            return;
        }
        for(int i = index; i <= 9; i++){
            if (t + i > target){
                break;
            }
            vec.push_back(i);
            combination(vec, depth+1, t + i, i + 1);
            vec.pop_back();
        }
    }
};
