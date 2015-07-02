class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int>> res;
        vector<int> vec;
        res.push_back(vec);
        sort(S.begin(), S.end());
        for(int i=0; i<S.size(); i++) {
            int n = res.size();
            for(int j=0; j<n; j++) {
                vec = res[j];
                vec.push_back(S[i]);
                res.push_back(vec);
            }
        }
        return res;
    }
};

/*
class Solution {
public:
    vector<vector<int>> res;
    int n;
    vector<vector<int>> subsets(vector<int>& nums) {
        res.clear();
        n = nums.size();
        std::sort(nums.begin(), nums.end());
        vector<int> vec;
        get(nums, vec, 0);
        return res;
    }

    void get(vector<int>& nums, vector<int>& vec, int index){
        //res.push_back(vec);
        if (index >= n){
            res.push_back(vec);
            return;
        }
        // for(int i = index; i < n; i++){
            get(nums, vec, index + 1);
            vec.push_back(nums[index]);
            get(nums, vec, index + 1);
            vec.pop_back();
        // }
    }
};
*/
