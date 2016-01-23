class Solution {

public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> res(k, 0);
        for (int i = std::max(0, int(k - nums2.size())); i <= std::min(k, int(nums1.size())); i++) {
            // res = max(res, mergeNumber(getNumber(nums1, i), getNumber(nums2, k-i)));
            vector<int> tmp = mergeNumber(getNumber(nums1, i), getNumber(nums2, k-i));
            if(getLargerOne(tmp, res, 0, 0) == true) {
                res = tmp;
            }
        }

        return res;
    }

    vector<int> getNumber(vector<int>& nums, int k) {
        vector<int> res;
        int to_drop = nums.size() - k;
        for (int num: nums) {
            while (to_drop > 0 && !res.empty() && res.back() < num) {
                res.pop_back();
                to_drop--;
            }
            res.push_back(num);
        }
        res.resize(k);
        return res;
    }

    bool getLargerOne(vector<int>& nums1, vector<int>& nums2, int index1, int index2) {
        while(index1 < nums1.size() && index2 < nums2.size()) {
            if (nums1[index1] < nums2[index2]){
                return false;
            }
            else if (nums1[index1] > nums2[index2]) {
                return true;
            }
            index1++;
            index2++;
        }

        if (index1 >= nums1.size()) {
            return false;
        }
        return true;
    }

    vector<int> mergeNumber(vector<int> nums1, vector<int> nums2) {
        vector<int> res;
        int i = 0, j = 0;
        while(i < nums1.size() && j < nums2.size()) {
            if (nums1[i] > nums2[j]) {
                res.push_back(nums1[i++]);
            }
            else if (nums1[i] == nums2[j]) {
                if(getLargerOne(nums1, nums2, i+1, j+1)){
                    res.push_back(nums1[i++]);
                }
                else{
                    res.push_back(nums2[j++]);
                }

            }
            else {
                res.push_back(nums2[j++]);
            }
        }

        while(i < nums1.size()) {
            res.push_back(nums1[i++]);
        }

        while(j < nums2.size()) {
            res.push_back(nums2[j++]);
        }
        return res;
    }

};

// TLE version
class Solution {
    int max_depth;
    int m;
    int n;
    vector<int> res;
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        m = nums1.size();
        n = nums2.size();
        max_depth = k;
        res.resize(k, -1);
        vector<int> cur;
        helper(nums1, nums2, 0, 0, cur);
        helper(nums2, nums1, 0, 0, cur);
        return res;
    }

    void helper(vector<int>& nums1, vector<int>& nums2,
                int index1, int index2, vector<int>& cur) {

        if (cur.size() > 0 && cur.size() < max_depth) {
            bool flag = true;
            for (int i = 0; i < cur.size(); i++) {
                flag = flag && (cur[i] <res[i]);
            }
            if (flag) {
                return;
            }
        }
        if (cur.size() == max_depth) {
            for (int i = 0; i < max_depth; i++) {
                if (cur[i] > res[i]){
                    res = cur;
                    break;
                }
                else if(cur[i] == res[i]) {
                    continue;
                }
                else{
                    break;
                }
            }
            return;
        }

        for (int i = index1; i < nums1.size(); i++) {
            cur.push_back(nums1[i]);
            helper(nums1, nums2, i + 1, index2, cur);
            helper(nums2, nums1, index2, i + 1, cur);
            cur.pop_back();
        }
    }
};
