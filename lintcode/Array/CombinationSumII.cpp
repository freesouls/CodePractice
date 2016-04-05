class Solution {
public:
	/**
	 * @param num: Given the candidate numbers
	 * @param target: Given the target number
	 * @return: All the combinations that sum to target
	 */
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // write your code here
        vector<vector<int> > res;

        sort(num.begin(), num.end());
        vector<int> vec;

        dfs(res, vec, num, 0, 0, target);
        return res;
    }

    void dfs(vector<vector<int> >& res, vector<int> vec, vector<int> &can, int index, int sum, int target) {
        if (sum == target) {
            res.push_back(vec);
            return;
        }

        for (int i = index; i < can.size(); i++) {
            if ( i > index && can[i] == can[i-1]) {
                continue;
            }
            if (sum + can[i] > target) {
                break;
            }
            else {
                vec.push_back(can[i]);
                dfs(res, vec, can, i + 1, sum + can[i], target);
                vec.pop_back();
            }
        }
    }
};
