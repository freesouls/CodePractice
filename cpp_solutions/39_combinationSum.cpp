class Solution {
public:
    vector<vector<int>> res;
    int t;
    int n;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        res.clear();
        sort(candidates.begin(), candidates.end());
        t = target;
        n = candidates.size();
        vector<int> vec;
        combination(candidates, vec, 0, 0);
        return res;
    }

    void combination(vector<int>& candidates, vector<int>& vec, int index, int target){
        if (target == t){
            res.push_back(vec);
            return;
        }
        for(int i = index; i < n; i++){
            if (i > index && candidates[i] == candidates[i-1]){
                continue;
            }
            if (target+candidates[i] > t){
                break;
            }
            vec.push_back(candidates[i]);
            combination(candidates, vec, i, target+candidates[i]);
            vec.pop_back();
        }
        // return 0;
    }
};
