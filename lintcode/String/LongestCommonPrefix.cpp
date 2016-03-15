class Solution {
public:
    /**
     * @param strs: A list of strings
     * @return: The longest common prefix
     */
    string longestCommonPrefix(vector<string> &strs) {
        // write your code here
        string prefix = "";
        if (strs.size() == 0) {
            return prefix;
        }
        int index = 0;
        while (true) {
            if (index < strs[0].length()){
                char cur = strs[0][index];
                for (int i = 1; i < strs.size(); i++) {
                    if (index < strs[i].length() && cur == strs[i][index]) {
                        continue;
                    }
                    else{
                        return prefix;
                    }
                }
                prefix.push_back(cur);
                ++index;
            }
            else{
                return prefix;
            }
        }
        return prefix;
    }
};
