class Solution {
public:
    /**
     * @param s a string,  encoded message
     * @return an integer, the number of ways decoding
     */

    // dp[i] = dp[i-1] + dp[i-2]; if s[i-1, i] <= '26'
    // dp[i] = dp[i-1]; if s[i-1, i] > 16
    int numDecodings2(string& s) {
        // Write your code here
        if (s.length() == 0 || s[0] == '0') {
            return 0;
        }

        vector<int> dp(s.length()+1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 1; i < s.length(); i++) {
            if (s[i-1] == '0' && s[i] == '0') {
                return 0;
            }

            if (s[i] == '0') {
                dp[i+1] = dp[i];
                dp[i] = 0;
            }

            if (s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6') ) {
                dp[i+1] = dp[i] + dp[i-1];
            }
            else {
                dp[i+1] = dp[i];
            }
        }
        return dp[s.length()];

    }

    int numDecodings(string& s) {
        if (s.length() == 0 || s[0] == '0') {
            return 0;
        }

        // vector<int> dp(s.length()+1, 0);
        int prev = 1;
        int prev_prev = 1;
        int cur = 0;
        for (int i = 1; i < s.length(); i++) {
            if (s[i-1] == '0' && s[i] == '0') {
                return 0;
            }

            if (s[i] == '0') {
                cur = prev;
                prev = 0;
            }

            if (s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6') ) {
                cur = prev + prev_prev;
            }
            else {
                cur = prev;
            }

            prev_prev = prev;
            prev = cur;
        }
        return prev;
    }
};
