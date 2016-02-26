class Solution {
public:
    /**
     * Determine whether s3 is formed by interleaving of s1 and s2.
     * @param s1, s2, s3: As description.
     * @return: true of false.
     */
    bool isInterleave(string s1, string s2, string s3) {
        // write your code here

        if (s1.length() + s2.length() != s3.length()) {
            return false;
        }
        
        return check(s1, 0, s2, 0, s3);
        
    }
    
    bool check(string& s1, int i, string& s2, int j, string& s3) {
        

        if (i == s1.length() && j == s2.length()) {
            return true;
        }
        
        if (i < s1.length() && s1[i] == s3[i+j]) {
            if (check(s1, i+1, s2, j, s3)) {
                return true;
            }
        }
        
        if (j < s2.length() && s2[j] == s3[i+j]) {
            if (check(s1, i, s2, j+1, s3)) {
                return true;
            }
        }
        
        return false;
    }
};