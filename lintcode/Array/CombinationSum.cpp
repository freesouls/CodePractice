class Solution {
public:
    /**
     * @param candidates: A list of integers
     * @param target:An integer
     * @return: A list of lists of integers
     */
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // write your code here
        vector<vector<int> > res;

        sort(candidates.begin(), candidates.end());
        vector<int> vec;

        dfs(res, vec, candidates, 0, 0, target);
        return res;
    }

    void dfs(vector<vector<int> >& res, vector<int> vec, vector<int> &can, int index, int sum, int target) {
        if (sum == target) {
            res.push_back(vec);
            return;
        }

        for (int i = index; i < can.size(); i++) {
            if (sum + can[i] > target) {
                break;
            }
            else {
                vec.push_back(can[i]);
                dfs(res, vec, can, i, sum + can[i], target);
                vec.pop_back();
            }
        }
    }
};
