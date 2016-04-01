class Solution {
public:
    /**
     * @param source: A string
     * @param target: A string
     * @return: A string denote the minimum window
     *          Return "" if there is no such a string
     */
    string minWindow(string &s, string &t) {
        // write your code here
        if (s.size() == 0 || s.size() < t.size()){
            return "";
        }
        int count[256];
        int cur[256];
        fill(count, count + 256, 0);
        fill(cur, cur + 256, 0);
        for (int i = 0; i < t.size(); i++){
            count[t[i]]++;
        }

        int minWidth = INT_MAX;
        int minStart = 0;
        int winStart = 0;
        int total = 0;
        for (int i = 0; i < s.size(); i++){
            if (count[s[i]] > 0){
                cur[s[i]]++;
                if (cur[s[i]] <= count[s[i]]){
                    total++;
                }
            }
            if (total == t.size()){
                while(cur[s[winStart]] > count[s[winStart]] || count[s[winStart]] == 0){
                    cur[s[winStart]]--;
                    winStart++;
                }

                if (minWidth > i - winStart + 1){
                    minWidth = i - winStart + 1;
                    minStart = winStart;
                }
            }
        }

        if (minWidth == INT_MAX){
            return "";
        }
        return s.substr(minStart, minWidth);
    }
};
