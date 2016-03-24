bool compare(string s1, string s2) {
    return (s1 + s2) > (s2 + s1);
}
class Solution {
public:
    /**
     *@param num: A list of non negative integers
     *@return: A string
     */
    string largestNumber(vector<int> &nums) {
        // write your code here
        vector<string> arr;
        for (int i = 0; i < nums.size(); i++) {
            arr.push_back(to_string(nums[i]));
        }

        sort(arr.begin(), arr.end(), compare);
        string res = "";
        for (int i = 0; i < arr.size(); i++) {
            res += arr[i];
        }
        if (res =="" || (res[0] == '0' && res.length() > 1)) {
            return "0";
        }

        return res;
    }
};
