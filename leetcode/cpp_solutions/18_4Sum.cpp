class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &nums, int target) {
        int n = nums.size();
        vector<vector<int> > res;
        unordered_map<int, vector<pair<int, int> > >pairs;
        pairs.reserve(n*n);
        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++)
            for(int j = i+1 ; j < n; j++)
                pairs[nums[i]+nums[j]].push_back(make_pair(i,j));

        for(int i = 0; i < n - 3; i++)
        {
            if(i > 0 && nums[i] == nums[i-1])continue;
            for(int j = i+1; j < n - 2; j++)
            {
                if(j > i+1 && nums[j] == nums[j-1])continue;
                if(pairs.find(target - nums[i] - nums[j]) != pairs.end())
                {
                    vector<pair<int, int>> &sum2 = pairs[target - nums[i] - nums[j]];
                    bool isFirstPush = true;
                    for(int k = 0; k < sum2.size(); k++)
                    {
                        if(sum2[k].first <= j)continue;
                        if(isFirstPush || (res.back())[2] != nums[sum2[k].first])
                        {
                            res.push_back(vector<int>{nums[i], nums[j], nums[sum2[k].first], nums[sum2[k].second]});
                            isFirstPush = false;
                        }
                    }
                }
            }
        }

        return res;
    }
};
